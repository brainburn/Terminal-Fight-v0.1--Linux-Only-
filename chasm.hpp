/*
 * Chasm.hpp
 *
 *  Created on: Dec 7, 2010
 *      Author: Nikola Chonkov
 *
 *  Implementation of class Chasm.
 */

#ifndef CHASM_HPP_
#define CHASM_HPP_

#define CHASM_VIEW "."		//Default chasm skin
#define CHASM_TYPE "chasm"

#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "map.hpp"

class Chasm : public Entity {
public:
	Chasm(int a, int b) : Entity(a, b, CHASM_TYPE, CHASM_VIEW){
	}

	//On collision with a chasm, die if Player. Stop if Enemy.
	bool collide(Entity *unit);

	//Print object type and exit
	void pr(){ cerr << "WALL" << endl; exit(0);}
};

#endif /* CHASM_HPP_ */
