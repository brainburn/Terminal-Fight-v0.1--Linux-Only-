/*
 * Chasm.cpp
 *
 *  Created on: Dec 7, 2010
 *      Author: Nikola Chonkov
 *
 * On a collision with a Chasm, the player dies. Enemies
 * Interpret a chasm as a Wall, this makes them seem to
 * be smart enough not to step in it.
 */

#include "chasm.hpp"

bool
Chasm::collide(Entity *unit){
	if(unit->type == "player"){
		Player::getPlayer(0,0)->setHealth(-1);
		Map::getMap()->setHud("While falling down with thousands of miles per hour,\n"\
							  "you realize that gravity still works. Game over.");
		return false;	//Player goes in
	}
	return true; // Enemies stay out
}
