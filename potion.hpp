/*
 * potion.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 *
 * Implementation of Potion class;
 * Potions can be picked by Player, and used
 * to increase the amount of the player's health
 */


#ifndef POTION_HPP_
#define POTION_HPP_

#include "entity.hpp"
#include "player.hpp"
#include "map.hpp"

class Potion: public Entity {
public:
	Potion(int value, int x, int y){
			//set skin
			this->skin[0][1] = "O";
			this->skin[1][1] = "^";

			//set health bonus
			this->setHealth(value);

			//set coordinates
			this->setXY(x, y);
		}

		//On collision with player, increase health,
		//on collision with enemy, remove from map
		bool collide(Entity* unit);
};

#endif /* POTION_HPP_ */
