/*
 * potion.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 */

#include "potion.hpp"

//On collision with player, increase health,
//on collision with enemy, remove from map
bool Potion::collide(Entity* unit){
	if(unit->type=="player"){
		Map* m = Map::getMap();
		Player *p = Player::getPlayer(0,0);
		stringstream ss;

		//Update health
		p->setHealth(p->getHealth() + this->getHealth());

		//Update HUD
		ss << " You found a Bottle of ACME Aspirin (R) !" << endl;
		ss << " Your health is now " << p->getHealth();
		m->setHud(ss.str());
	}
	return false;
}
