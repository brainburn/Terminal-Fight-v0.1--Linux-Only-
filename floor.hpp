/*
 * floor.hpp
 *
 *  Created on: Dec 7, 2010
 *      Author: Nikola Chonkov
 *
 * Implementation of Floor class;
 * The only behavior is that it does not
 * modify unit's behavior and states.
 */


#ifndef FLOOR_HPP_
#define FLOOR_HPP_

#define FLOOR_VIEW " "
#define FLOOR_TYPE "floor"

#include "entity.hpp"


class Floor: public Entity {
public:
	Floor(int a, int b) : Entity(a, b, FLOOR_TYPE,FLOOR_VIEW){
	}

	//Print object type
	void pr(){ cerr << "FLOOR" << endl; exit(0);}
};

#endif /* FLOOR_HPP_ */
