/*
 * friend.cpp
 *
 *  Created on: Dec 10, 2010
 *      Author: Nikola Chonkov
 */

#include "friend.hpp"

bool

//Dialog on collision: Friend will offer you to
//Improve your abilities in exchange for crystals;

Friend::collide(Entity* unit){
	if(unit->type=="player"){
		Player *p = Player::getPlayer(0,0);
		Map *m = Map::getMap();
		stringstream ss;
		char q = 0;
		ss << "Hello, my friend. Would you like me to teach you\n some skills in exchange for 1000 crystals? (y/n)";
		ss << endl << endl;
		ss << "Your crystals: " << p->money;
		m->setHud(ss.str());

		//Ask for answer
		while(q != 'y' || q!='n'){
			if(q == 'y'){
				if(p->money < 1000){
					m->setHud("\nSorry, but you do not have enough crystals...");
					break;
				}
				else{
					ss.clear();
					ss << "\n*BOOM* Open your eyes. You are much stronger now!";
					p->setAttack(p->getAttack() + 10);
					p->setDefense(p->getDefense() + 10);
					ss << endl << "Your Attack: " << p->getAttack();
					ss << endl << "Your Defense: " << p->getDefense();
					m->setHud(ss.str());
					break;
				}
			}
			if(q == 'n')
				break;
			q = mygetch();
		}
	}
	return true;
}

//Places Friend on the map
void
Friend::putUnit(Map *m){
	if(m->getBox(this->x, this->y) != this){
		delete m->getBox(this->x, this->y);
		m->setMap(this->x, this->y, this);
		cout << "\033[2J\033[1;1H";
		cout << m->printmap();
	}
}
