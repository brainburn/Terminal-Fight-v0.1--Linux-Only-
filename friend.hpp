/*
 * friend.hpp
 *
 *  Created on: Dec 10, 2010
 *      Author: Nikola Chonkov
 *
 * Implements Friend class; All a Friend does
 * is interact with the player on a collision.
 * It doesn't move, take damage, or die.
 */

#ifndef FRIEND_HPP_
#define FRIEND_HPP_

#include "unit.hpp"
#include "player.hpp"
#include "map.hpp"
#include "mygetch.hpp"

class Friend: public Unit {
public:
	Friend(int x, int y): Unit("F"){
		this->setXY(x, y);
		this->type="friend";
	}

	//Trade on collision
	bool collide(Entity* unit);

	//Print object type and exit
	void pr(){ cerr << "Friend" << endl; exit(0);}

	//Places unit on the map
	void putUnit(Map *m);

	//take damage: no functionality
	void takeDamage(Player* unit){}

	//die: no functionality
	void die(){}

	//movement: no functionality
	void moveTo(Map *m, int x, int y){}
	void moveLeft(Map *m){}
	void moveRight(Map *m){}
	void moveUp(Map *m){}
	void moveDown(Map *m){}
};

#endif /* FRIEND_HPP_ */
