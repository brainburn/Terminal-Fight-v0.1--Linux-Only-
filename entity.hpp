/*
 * entitiy.h
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 *
 * The Entity class stands in the base of every other object
 * in the game, and thus it can be a reference to any object.
 * This is the most basic type of object that can be used in the game.
 */

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#define SKIN_HEIGHT 3
#define SKIN_WIDTH  3

#pragma once
#include "tools.hpp"

using namespace std;

class Entity {
private:
	int health;  //Health value. When <= 0, the object is usually destroyed.
	int attack;  //Attack value.
	int defense; //Defense value.
public:
	string skin[SKIN_HEIGHT][SKIN_WIDTH]; // An NxN grid, representing the appearance of the object on screeen.
	int x; // X - coordinates of the object on the map.
	int y; // Y - coordinates of the object on the map.
	int id;// Object identification number. Can be used to distinguish between different instances of a class.
	string type; // Object type. Used to differentiate between the derivatives of Entity.
	string pxl; // Unless a custom skin is specified, the skin grid is filled with this value;

	Entity()
		:health(0),
		 attack(0),
		 defense(0),
		 x(0),
		 y(0),
		 id(0),
		 type("none"),
		 pxl(" "){

		for(int i = 0; i < SKIN_HEIGHT; i++){
			for(int j = 0; j < SKIN_WIDTH; j ++){
				skin[i][j] = pxl;
			}
		}
	}

	Entity(int a, int b, string t, string s)
		:health(0),
		 attack(0),
		 defense(0),
		 x(a),
		 y(b),
		 id(0),
		 type(t),
		 pxl(s){

		for(int i = 0; i < SKIN_HEIGHT; i++){
				for(int j = 0; j < SKIN_WIDTH; j ++){
					skin[i][j] = pxl;
				}
			}
		}
	virtual ~Entity(){
	}

	//Health setters and getters.
	virtual int getHealth(){return health;}
	virtual void setHealth(int h){ this->health = h;}

	//Attack setters and getters.
	virtual int getAttack(){return attack;}
	virtual void setAttack(int a){ this->attack = a;}

	//Defense setters and getters.
	virtual int getDefense(){return defense;}
	virtual void setDefense(int d){ this->defense = d;}

	//Returns a string representing the requested row of the object's skin matrix
	virtual string getRow(int row);

	//A shortcut to setting the object's X and Y coordinates
	virtual void setXY(int x, int y);

	//Collision detector. If it returns true, the object cannot "step" on this entity.
	//It also modifies unit, depending on what it bumped into.
	virtual bool collide(Entity *unit){ return false; }

	//Print the object type
	virtual void pr(){ cerr << "ENT" << endl;}
};

#endif /* ENTITY_HPP_ */
