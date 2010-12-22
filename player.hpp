/*
 * Player.h
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 *
 * Implements Player class; This class is implemented
 * as a singleton, because we want to be sure that at
 * any point in the game, we are working with the same
 * instance of Player. Moreover, the Player object is
 * the most interactive and modified object, so we want
 * to be sure that all the changes are applied to the same
 * object. Map transition is also more easily and more
 * intuitively done with a singleton Player.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#pragma once
#include "unit.hpp"
#include "floor.hpp"
#include "map.hpp"




class Player: public Unit{
private:
	static Player* player;
	Player(int x, int y):Unit("M"){
		this->setXY(x, y);
		this->type="player";
		this->money		= 0;
		this->level		= 0;
		this->experience = 0;
		this->weapon = NULL;
	}
public:
	int money;			// Amount of crystals possessed.
	int level;			// Current level
	int experience;		// Current experience. If >=50, player gains a level
	Entity *weapon;		// Weapon wielded, if any

	~Player(){
		if(this->weapon != NULL)
			delete weapon;
	}

	//If there is an instance of player, it returns the instance;
	//If there is not, it allocates a new one, and returns it
	//with coordinates set to the given (still needs to be put on map)
	static Player* getPlayer(int x, int y);

	//Used to set the static pointer, pointing to the singleton to NULL;
	//If not used after player is deallocated, memory corruption will occur if
	//getPlayer() is called;
	static void    newPlayer();

	//Returns player's attack. More specific, since player can wield a weapon.
	int  getAttack();

	//Player's way to take damage. More specific since player can gain levels,
	//and possibly use a shield.
	void takeDamage(Entity* unit);

	//Update attributes on level up
	void levelUp();

	//Behavior for when health <= 0
	void die();

	//What happens when someone bumps into me
	bool collide(Entity* unit){ takeDamage(unit); return true;}

	//Print the object type and exit
	void pr(){ cerr << this->type << endl; exit(0);}

	//Places unit on the map, with the coordinates that it is set to have
	void putUnit(Map *m);

	//The rest of the functions implement player's movement
	void moveTo(Map *m, int x, int y);
	void moveLeft(Map *m);
	void moveRight(Map *m);
	void moveUp(Map *m);
	void moveDown(Map *m);
};


#endif /* PLAYER_H_ */
