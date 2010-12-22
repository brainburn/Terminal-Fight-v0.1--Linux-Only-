/*
 * Map.cpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 */

#include "map.hpp"

//Initializing the pointer to the map instance
Map* Map::map = NULL;

//If a map instance exists, return it. Otherwise, create one and return it
Map*
Map::getMap(){
	if(map == NULL){
		map = new Map();
		cerr<<"Constructing map...\n";
	}
	return map;
}

//Set the static pointer to the instance to NULL. Need if we want to delete
//the old map and allocate a new one. If not used, memory corruption will occur.
void
Map::newMap(){
	map = NULL;
}

//Returns a string containing the visual representation of the map. It creates it so row by row
//- for a 10x20 map of Entities, with each Entity object having 3 rows,there would be 30 such
//rows. IT concatenates each row of the skin of each Entity object to a string. When it is done,
//it appends the HUD, it clears the screen,by putting the cursor in the top left part, and returns the string.
string
Map::printmap(){
	string mp(""); //string to contain the textual representation of the map

	//Concatenating each row, of each entity to the string
	for(int i = 0; i < MAP_HEIGHT; i++){
		for(int row = 0; row < SKIN_HEIGHT; row++){
			for(int j = 0; j < MAP_WIDTH; j ++){
				mp.append(map_matrix[i][j]->getRow(row)); //get row "row" from the skin of the current Entity
			}
			mp.append("|");
			mp.append("\n");
		}
	}

	//Put a separator line, dividing the screen into a map part, and hud part, and add the hud.
	for(int i = 0; i < MAP_WIDTH; i++){
			mp.append("___");
		}
		mp.append("\n");
		mp.append(hud + "\n");
		mp.append("\n");

	//Clear the screen
	cout << "\033[2J\033[1;1H";


	return mp;
}

//Places a unit on the map, and reprints it to show the changes
void
Map::putUnit(Entity* e){
	delete getBox(e->x, e->y);
	setMap(e->x, e->y, e);
	cout << printmap();
}
