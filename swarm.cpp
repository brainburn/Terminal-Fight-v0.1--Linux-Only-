/*
 * swarm.cpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 */

#include "swarm.hpp"
Swarm* Swarm::swrm = NULL; //A pointer to the static instance of swarm

//Return a pointer to the swarm, if there is one.
//If Swarm was not initialized, initialize it.
Swarm*
Swarm::getSwarm(){
	if(swrm == NULL)
		swrm = new Swarm();
	return swrm;
}

//Nulls the pointer to singleton swarm. Needed to
//prevent memory corruption in future.
void
Swarm::newSwarm(){
	swrm = NULL;
}

//Add an enemy to the swarm
void
Swarm::add(Enemy* enemy){
	swarm.push_back(enemy);
}

//Remove element with id = i from the swarm
void
Swarm::remove(int i){
	list<Enemy*>::iterator it;
	advance(it, i);
	swarm.erase(it);
}

//Make the swarm perform an action
void
Swarm::act(){
	list<Enemy*>::iterator it;
	for(it = swarm.begin(); it != swarm.end(); it++){
		if((*it)->getHealth() <= 0){
			(*it)->die();
			swarm.erase(it);
			return;
		}
		(*it)->findPlayer();
	}
}
