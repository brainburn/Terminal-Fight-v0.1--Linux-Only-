/*
 * swarm.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 *
 * Implementation of the Swarm class. I needed a simple Publisher-Subscriber design pattern
 * so that I could make all the enemies move towards me and attack me. Since I did not know
 * how many of them there would be, I needed to keep a list. I also needed a fast way
 * to send messages to all of the members of the list, and I needed to be able to
 * remove elements from it easily. The STL list worked well for this purpose.
 */

#ifndef SWARM_HPP_
#define SWARM_HPP_

#pragma once
#include "map.hpp"
#include "enemy.hpp"
#include <list>
class Swarm{
private:
	static Swarm* swrm;	//A pointer to the static instance of swarm
	list<Enemy*> swarm; //A list of the elements in the swarm
	Swarm(){
	}
public:
	~Swarm(){
		swarm.clear();
	}

	//Return a pointer to the swarm, if there is one.
	//If Swarm was not initialized, initialize it.
	static Swarm* getSwarm();

	//Nulls the pointer to singleton swarm. Needed to
	//prevent memory corruption in future.
	static void newSwarm();

	//Add an enemy to the swarm
	void add(Enemy* enemy);

	//Remove element with id = i from the swarm
	void remove(int i);

	//Make the swarm perform an action
	void act();

	//Return the size of the swarm
	int getSize() {return swarm.size();}
};

#endif /* SWARM_HPP_ */
