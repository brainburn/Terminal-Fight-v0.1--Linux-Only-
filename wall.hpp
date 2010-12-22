/*
 * wall.hpp
 *
 *  Created on: Dec 7, 2010
 *      Author: Nikola Chonkov
 */

#ifndef WALL_HPP_
#define WALL_HPP_

#define WALL_VIEW "#"	//Default wall skin
#define WALL_TYPE "wall"

#include "entity.hpp"

class Wall: public Entity {
public:
	Wall(int a, int b) : Entity(a, b, WALL_TYPE, WALL_VIEW){
	}

	//On a collision with a wall, stop object
	bool collide(Entity *unit){return true;}

	//Print object type and exit
	void pr(){ cerr << "WALL" << endl; exit(0);}
};

#endif /* WALL_HPP_ */
