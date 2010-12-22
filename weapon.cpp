/*
 * weapon.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 */

#include "weapon.hpp"

//On collision, player drops the weapon he carries (if he had one)
//and picks the new one. Enemies remove weapons from map
bool
Weapon::collide(Entity* unit){
	if(unit->type == "player"){
		Map* m = Map::getMap();
		Player *p = Player::getPlayer(0,0);
		stringstream ss;

		//Pick new weapon
		if(p->weapon != NULL)
			delete p->weapon;
		p->weapon = new Weapon(this->name, this->getAttack(), this->x, this->y);

		//Update HUD
		ss << " You found a " << this->name <<" !" << endl;
		ss << " Your attack was increased to " << p->getAttack();
		m->setHud(ss.str());
	}
	return false;
}
