/*
 * game.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 */

#include "game.hpp"


//Displays a welcome screen in the beginning of the game
void
hello(){
	stringstream ss;
	string title = "Welcome to Terminal Fight I!";
	string view = "\nMaximize terminal window for best experience!\n\n";
	string controls = "Controls: \nw = up, s = down, a = left, d = right.\n";
	       controls += "Walk into an enemy repeatedly to attack them.";
	string anyKey = "Press any key to continue. Press any other key to exit :)";

	ss << "\033[2J\033[1;1H";
	for(int i = 0; i < MAP_HEIGHT/2; i++)
		ss << endl;
	for(int i = 0; i < MAP_WIDTH; i++)
		ss << "~~~";
	ss << endl;
	for(int i = 0; i < (MAP_WIDTH); i++)
		ss <<  " ";
	ss << title << endl;
	for(int i = 0; i < MAP_WIDTH; i++)
		ss << "~~~";
	ss << endl;
	ss << view;
	ss << controls << endl << endl << endl;
	ss << anyKey << endl;
	cout << ss.str();
	mygetch();
}

//Displays a "bye" screen in the end of the game
void
eofGame(){
	stringstream ss;
	ss <<"Congratulations, you won!\n";
	for(int i = 0; i < MAP_WIDTH; i++)
		ss << "~~~";
	ss << endl;
	ss << endl << "Your level " << Player::getPlayer(0,0)->level;
	ss << endl << "Your Attack: " << Player::getPlayer(0,0)->getAttack();
	ss << endl << "Your Defense: " << Player::getPlayer(0,0)->getDefense();
	ss << endl << "Your Cristals: "<< Player::getPlayer(0,0)->money;
	ss << endl;
	cout << ss.str();
	mygetch();
}

//Load map mapName. A map is a list of the object on the map, together with their coordinates, and
//their special values (name, attack value, healing value...) if any. Initially, a map is
//represented just by floor objects. everything is placed on it after that.
//It is important that the objects are placed on the map in the order specified here, since
//each placement removes the object that stood below it.

Map*
Game::loadMap(string mapName){
	Map *map = Map::getMap(); //Get a pointer to a map singleton
	ifstream mapFile;		  //Map file
	string line;			  //A line in the map file

	//If no next map, return current map
	if(mapName == ""){
		return map;
	}
	mapFile.open(mapName.c_str(), ifstream::in);

	//Check if mapname is a valid mapname
	if(!mapFile.is_open()){
		cerr<<"Could not find map\n";
		exit(0);
	}
	else{
	//Start reading from file. Objects are created in the following order:
	//Floor, Wall, Chasm, Weapon, Crystals, Potion, Enemy, Friend, Player, nextLevel
	//The coordinates and other special values are extracted by substing extraction.
	//Each object has its own signature.
	//The general order is - get coordinates and special values. Construct the corresponding objects
	//with them, and put them on the map. Enemies are peculiar with this that they need to be added
	//to a "swarm", or a specialized publisher/subscriber design pattern that will enable us
	//to send messages to all of them at once.
		while(!mapFile.eof()){
			getline(mapFile, line);
			if(line == "+FLOOR"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					string x = line.substr(1, 2);
					string y  =line.substr(5, 2);
					map->putEntity(new Floor(atoi(y.c_str()), atoi(x.c_str())));
					getline(mapFile, line);
				}
			}
			if(line == "+WALL"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					string x = line.substr(1, 2);
					string y  =line.substr(5, 2);
					map->putEntity(new Wall(atoi(y.c_str()), atoi(x.c_str())));
					getline(mapFile, line);
				}
			}
			if(line == "+CHASM"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					string x = line.substr(1, 2);
					string y  =line.substr(5, 2);
					map->putEntity(new Chasm(atoi(y.c_str()), atoi(x.c_str())));
					getline(mapFile, line);
				}
			}
			if(line == "+WEAPONS"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					int last_sep = 0;
					last_sep = line.find(",");
					string name = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string damage = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string x = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string y = line.substr(1, last_sep - 1);

					map->putEntity(new Weapon(name,
											  atoi(damage.c_str()),
											  atoi(y.c_str()),
											  atoi(x.c_str())));
					getline(mapFile, line);
				}
			}
			if(line == "+CRYSTALS"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					int last_sep = 0;
					last_sep = line.find(",");
					string value = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string x = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string y = line.substr(1, last_sep - 1);

					map->putEntity(new Crystals(atoi(value.c_str()),
											   atoi(y.c_str()),
											   atoi(x.c_str())));

					getline(mapFile, line);
				}
			}
			if(line == "+POTION"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					int last_sep = 0;
					last_sep = line.find(",");
					string value = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string x = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string y = line.substr(1, last_sep - 1);

					map->putEntity(new Potion(atoi(value.c_str()),
											   atoi(y.c_str()),
											   atoi(x.c_str())));
					getline(mapFile, line);
				}
			}
			if(line == "+ENEMY"){
				Swarm *swarm = Swarm::getSwarm();
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					int last_sep = 0;
					Enemy *enemy;
					last_sep = line.find(",");
					string x = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(")");
					string y = line.substr(1, last_sep - 1);

					enemy = new Enemy(atoi(y.c_str()),
									  atoi(x.c_str()));

					swarm->add(enemy);
					map->putEntity(enemy);
					getline(mapFile, line);
				}
			}
			if(line == "+FRIEND"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					int last_sep = 0;
					Friend *fr;
					last_sep = line.find(",");
					string x = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(",");
					string y = line.substr(1, last_sep - 1);

					fr = new Friend(atoi(y.c_str()),
									  atoi(x.c_str()));

					map->putEntity(fr);
					getline(mapFile, line);
				}
			}
			if(line == "+PLAYER"){
				getline(mapFile, line);
				while(!mapFile.eof() && line[0] != '+'){
					int last_sep = 0;
					last_sep = line.find(",");
					string x = line.substr(1, last_sep - 1);

					line = line.substr(last_sep + 1);
					last_sep = line.find(")");
					string y = line.substr(1, last_sep - 1);

					Player *p = Player::getPlayer(atoi(y.c_str()),
												 atoi(x.c_str()));
					map->putUnit(p);
					getline(mapFile, line);
				}
			}
			if(line == "+NLEVEL"){
				getline(mapFile, line);
					this->nextLevel = line;
			}
		}
	}
	return map;

}

//Controls the flow of the game.
void
Game::start(){
	Player *p = Player::getPlayer(5, 4); // Pointer to player singleton
	Map    *m = loadMap("map1");		 // Pointer to map singleton
	char    s = 0;

	hello(); 			   //print the welcome screen
	cout << m->printmap(); //print the map

	//Read player's controls
	while(s != 'q'){
		if(s == 'w')
			p->moveUp(m);
		if(s == 's')
			p->moveDown(m);
		else if(s == 'a')
			p->moveLeft(m);
		else if (s == 'd')
			p->moveRight(m);
		//After the player has moved, all the enemies make a move themselves
		Swarm::getSwarm()->act();

		//If player is dead after the round, end the game
		if(p->getHealth() <= 0){
			cout << m->printmap();
			mygetch();
			return;
		}

		//If there are no more enemies, move to next level
		else if(Swarm::getSwarm()->getSize() == 0){
			//If no more levels, print goodbye screen and end game;
			if(nextLevel == ""){
				eofGame();
				return;
			}

			//replace the player from the map, so that he or she is not
			//deallocated
			m->setMap(p->x, p->y, new Entity());

			//end this level
			end();

			//reset singleton pointers
			Map::newMap();
			Swarm::newSwarm();

			//load next level, and put player there
			m = loadMap(nextLevel);
			p = Player::getPlayer(5, 4);
			nextLevel="";
		}
		//get next command
		s = mygetch();
	}
}
