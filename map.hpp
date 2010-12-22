/*
 * Map.h
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 *
 * Implementation of the Map class. A map is represented by a NxN matrix, each cell of which
 * is a object of class Entity. Since only one instance of this class is needed at a time,
 * and it is the most heavily used object, together with player, I made it a singleton.
 */
#pragma once
#include "entity.hpp"
#include "wall.hpp"
#include "floor.hpp"

#ifndef MAP_H_
#define MAP_H_

#define MAP_HEIGHT 10
#define MAP_WIDTH  20

class Map: public Entity {
private:
	//A pointer to the map instance
	static Map *map;

	//the Human User Display - the little screen below the map, informing the player of
	//what is going on in the game
	string hud;

	//the map itself
	Entity *map_matrix[MAP_HEIGHT][MAP_WIDTH];

	Map(): hud("Playing...\n") {
		for(int i = 0; i < MAP_HEIGHT; i++){
			for(int j = 0; j < MAP_WIDTH; j++){
				map_matrix[i][j] = new Floor(j, i);
				map_matrix[i][j]->x = j;
				map_matrix[i][j]->y = i;
			}
		}
	}

public:
	virtual ~Map(){
		cerr << "Destroying map..."<<endl;
		for(int i = 0; i < MAP_HEIGHT; i++){
			for(int j = 0; j < MAP_WIDTH; j++){
				if(map_matrix[i][j]!= NULL)
					delete map_matrix[i][j];
			}
		}
	}

	//If a map instance exists, return it. Otherwise, create one and return it
	static Map* getMap();

	//Set the static pointer to the instance to NULL. Need if we want to delete
	//the old map and allocate a new one. If not used, memory corruption will occur.
	static void newMap();

	//Update the hud screen with the message passed
	void 		 setHud   (string msg){ hud = msg; cout << Map::getMap()->printmap();}

	//print the type of the object, located at x,y
	void		 prc	  (int x, int y) { map_matrix[x][y]->pr();}

	//sets the x,y position on the map to the entity e
	void   		 setMap   (int x, int y, Entity *e) { map_matrix[y][x] = e;}

	//Places a unit on the map, and reprints it to show the changes
	virtual void putUnit  (Entity* e);

	//Puts an entity on the map without reprinting it. Used to build the map
	virtual void putEntity(Entity* e){ delete getBox(e->x, e->y); setMap(e->x, e->y, e);}

	//Prints the map
	string 		 printmap ();

	//returns the pointer to the object at x,y on the map
	Entity 		*getBox   (int x, int y){ return map_matrix[y][x]; }
};

#endif /* MAP_H_ */
