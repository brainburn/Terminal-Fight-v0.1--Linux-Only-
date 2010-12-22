/*
 * Player.cpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 */

#include "player.hpp"

//Player instance
Player* Player::player = NULL;


//If player exists, return it; if not, create it.
Player*
Player::getPlayer(int x, int y){
	if(player == NULL){
		player = new Player(x, y);
		cerr << "Constructing new player...\n";
	}
	return player;
}

//Player level up. Increase attack, defense and level, and give 1000 crystals bonus.
void
Player::levelUp(){
	stringstream ss;
	this->level++;
	this->experience = 0;
	this->setAttack(this->getAttack() + 5);
	this->setDefense(this->getDefense() + 5);
	this->money += 1000;

	//Update the HUD (human user display)
	ss << "You gained a level!" << endl;
	ss << "You are now level " << this->level;
	ss << endl << "Your Attack: " << this->getAttack();
	ss << endl << "Your Defense: " << this->getDefense();
	ss << endl << "Your Cristals: "<< this->money;

	Map::getMap()->setHud(ss.str());
}

//Set the pointer to the player instance to NULL.
void
Player::newPlayer(){
	player = NULL;
}

//Return player's attack
int
Player::getAttack(){
	int attack = this->Entity::getAttack();
	if(weapon != NULL)
		attack += weapon->getAttack();
	return attack;
}

//Implement the way in which player takes damage
void
Player::takeDamage(Entity* unit){
	Map         *map = Map::getMap();
	stringstream hud;
	int damage = 0;

	//50% chance of the enemy's attack being successful;
	//Makes the game easier, and can be used to set
	//Different difficulty levels on a further modification
	srand(time(NULL));
	if(rand()%2 == 0){
		damage  = unit->getAttack() + getDefense();
		if (damage >= 0){
			damage = 5;
		}
		setHealth(getHealth() -damage);
	}

	//Update the HUD
	hud << "Enemy Life: " << unit->getHealth() << "		Your Life: " << getHealth() << endl;
	hud << "Enemy Defense: " << unit->getDefense() << "	Your Defense: " << getDefense() << endl;
	hud << "Enemy Attack: " << unit->getAttack() << "	Your Attack: " << getAttack() << endl;
	map->setHud(hud.str());

	//If player runs out of health, kill the player
	if(this->getHealth() <= 0)
		die();
}

//Implements death behavior. Currently only updates the HUD, but
//can be modified in many ways in future.
void
Player::die(){
	Map::getMap()->setHud("You fight like a lion in this uneven battle,\n"\
							"but even lions can bleed. Game over.");
}

//Places unit on the map.
void
Player::putUnit(Map *m){
	if(m->getBox(this->x, this->y) != this){
		//If whatever is at this point is not
		//me, remove it, and put me there.
		delete m->getBox(this->x, this->y);
		m->setMap(this->x, this->y, this);

		//Clear the screen and redisplay changes
		cout << "\033[2J\033[1;1H";
	}
	cout << m->printmap();
}

//Moves player to the given point
void
Player::moveTo(Map *m, int x, int y){
	//Make sure that player is constrained by
	//map, and check for collisions.
	if((y < MAP_HEIGHT && y >= 0) &&
	   (x < MAP_WIDTH && x >= 0)&&
	   !m->getBox(x, y)->collide(this)){

		//Replace the empty spot behind me by a piece of Floor
		Floor *b = new Floor(this->x, this->y);

		//Move unit
		m->setMap(this->x, this->y, b);
		this->setXY(x, y);
		putUnit(m);
	}
	else{
		putUnit(m);
	}
}

//Makes the Player face to the left, and moves it
void
Player::moveLeft(Map *m){
	this->skin[0][0]="|";
	this->skin[0][2]=" ";
	this->skin[1][0]="+";
	this->skin[1][2]="\\";
	moveTo(m, this->x - 1,this->y);
}

//Makes the Player face to the right, and moves it
void Player::moveRight(Map *m){
	this->skin[0][0]=" ";
	this->skin[0][2]="|";
	this->skin[1][0]="/";
	this->skin[1][2]="+";
	moveTo(m, this->x + 1,this->y);
}

//Move up
void Player::moveUp(Map *m){
	moveTo(m, this->x,this->y - 1);
}

//Move down
void Player::moveDown(Map *m){
	moveTo(m, this->x,this->y + 1);
}
