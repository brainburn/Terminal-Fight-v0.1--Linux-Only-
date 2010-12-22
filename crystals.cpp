/*
 * crystals.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 */

#include "crystals.hpp"

//On collision with player, increase player's
//money. On collision with enemy, remove from map
bool
Crystals::collide(Entity* unit){
	if(unit->type=="player"){
		Map* m = Map::getMap();
		stringstream ss;
		Player* p = Player::getPlayer(0,0);

		//Increase player's money
		p->money += this->value;

		//Update HUD
		ss << " You found a pile of Crystals!" << endl;
		ss << " There are " << p->money << " crystals in your bag now.";
		m->setHud(ss.str());
	}
	return false;
}
