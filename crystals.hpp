/*
 * crystals.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 *
 * Implementation of Crystals class;
 * Crystals are the "monetary" unit in the game.
 */

#ifndef CRYSTALS_HPP_
#define CRYSTALS_HPP_

#include "entity.hpp"
#include "map.hpp"
#include "player.hpp"

class Crystals: public Entity {
private:
	int value;	// Anmount of crystals
public:
	Crystals(int value, int x, int y): value(value){
		//Define skin, coordinates, and amount = value;
		skin[1][1] = "*";
		skin[2][0] = "*";
		skin[2][1] = "*";
		skin[2][2] = "*";
		setXY(x, y);
	}
	//On collision with player, increase player's
	//money. On collison with enemy, remove from map
	bool collide(Entity* unit);
};

#endif /* CRYSTALS_HPP_ */
