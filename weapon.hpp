/*
 * weapon.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 *
 * Implementation of Weapon class;
 * Weapons can be picked by Player, and used
 * to increase the damage dealt
 */

#pragma once
#include "entity.hpp"
#include "player.hpp"
#include "map.hpp"

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

class Weapon: public Entity {
	string name;	//Weapon's name
public:
	Weapon(string name, int attack, int x, int y):name(name){
		//Set skin
		skin[0][1] = "|";
		skin[1][1] = "+";

		//Set attack bonus
		this->setAttack(attack);

		//Set coordinates
		setXY(x, y);
	}
	//On collision, player drops the weapon he carries (if he had one)
	//and picks the new one. Enemies remove weapons from map
	bool collide(Entity* unit);
};

#endif /* WEAPON_HPP_ */
