/*
 * unit.hpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 *
 * An polymorphic class, acting as a interface to the Unit-type
 * objects in the game
 */


#ifndef UNIT_HPP_
#define UNIT_HPP_

#pragma once
#include "map.hpp"

#define STARTING_HEALTH 100
#define STARTING_ATTACK 20
#define STARTING_DEFENSE 10

class Unit: public Entity{
public:
	Unit(){
	}
	Unit(string body){
		//Construct the way the unit is going to look.
		//Since all units are humanoid, they differ only in the
		//way their bodies look. Usually: M (Me) for Player, E for Enemy
		//and F for friend.
		this->skin[0][0]=" "; this->skin[0][1]="0"; this->skin[0][2]="|";
		this->skin[1][0]="/"; this->skin[1][1]=body; this->skin[1][2]="+";
		this->skin[2][0]="/"; this->skin[2][1]=" "; this->skin[2][2]="\\";

		this->setHealth(STARTING_HEALTH);
		this->setAttack(STARTING_ATTACK);
		this->setDefense(STARTING_DEFENSE);
	};

	virtual ~Unit(){
	}

	//Implements changes that occur when health <= 0
	virtual void 	die() = 0;

	//Used to place unit on the map. Since different units
	//are different objects, they are placed differently
	virtual void 	putUnit(Map *m)=0;

	//"Moves" the unit to the given point on the map
	virtual void 	moveTo(Map *m, int x, int y) = 0;

	//Step left
	virtual void 	moveLeft(Map *m) = 0;

	//Step right
	virtual void 	moveRight(Map *m)= 0;

	//Step up
	virtual void 	moveUp(Map *m)   = 0;

	//Step down
	virtual void 	moveDown(Map *m) = 0;

};

#endif /* UNIT_HPP_ */
