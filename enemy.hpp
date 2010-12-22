/*
 * enemy.hpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 *
 * Implements the Enemy Class, which really is a specialized
 * entity, with function prototypes derived from Unit.
 * Also implements a simple Enemy AI algorithm.
 */

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#pragma once
#include "unit.hpp"
#include "player.hpp"
#include "map.hpp"
#include "floor.hpp"

class Enemy: public Unit {
public:
	Enemy(int x, int y): Unit("E"){
		this->id = 0;
		this->setXY(x, y);
		this->type="enemy";
	}

	//Enemy's way to take damage.
	void takeDamage(Player* unit);

	//A simple algorithm that makes the
	//Enemy go to the player and attack it.
	void findPlayer();

	//Behavior for when health <= 0
	void die();

	//Print the object type and exit
	void pr(){ cerr << "Enemy" << endl; exit(0);}

	//Places unit on the map, with the coordinates that it is set to have
	void putUnit(Map *m);

	//What happens when someone bumps into the enemy
	bool collide(Entity* unit);

	//The rest of the functions implement enemy's movement
	void moveTo(Map *m, int x, int y);
	void moveLeft(Map *m);
	void moveRight(Map *m);
	void moveUp(Map *m);
	void moveDown(Map *m);
};

#endif /* ENEMY_HPP_ */
