/*
 * game.hpp
 *
 *  Created on: Dec 9, 2010
 *      Author: Nikola Chonkov
 *
 *  Implementation of the Game Class. This class puts everything together.
 *  It uses an external map file to initialize the map matrix. Each map
 *  represents a single level, and a map can specify the next level
 *  the game should proceed to once it is done with the current one, thus
 *  forming a "campaign". A level is considered finished when all the enemies
 *  in it have been killed. If the game is a campaign game, the items that a
 *  player carries, together with their attributes are preserved.
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#pragma once
#include "mygetch.hpp"

#include "entity.hpp"
#include "map.hpp"
#include "swarm.hpp"
#include "unit.hpp"

#include "player.hpp"
#include "enemy.hpp"
#include "friend.hpp"

#include "wall.hpp"
#include "floor.hpp"
#include "chasm.hpp"

#include "weapon.hpp"
#include "potion.hpp"
#include "crystals.hpp"


using namespace std;

class Game {
private:
	//load map mapName
	Map* loadMap(string mapName);
public:
	string nextLevel;
	Game():nextLevel(""){};
	~Game(){};

	//start game
	void start();

	//end game
	void end(){
		delete Map::getMap();
		delete Swarm::getSwarm();
	}

};

#endif /* GAME_HPP_ */
