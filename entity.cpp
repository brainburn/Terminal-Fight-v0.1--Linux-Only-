/*
 * entitiy.cpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 */
#include "entity.hpp"

//Returns a string representing the requested row of the object's skin matrix
string
Entity::getRow(int row){
	string bx("");
	for(int j = 0; j < SKIN_WIDTH; j ++){
		bx.append(skin[row][j]);
	}
	return bx;
}

//A shortcut to setting the object's X and Y coordinates
void
Entity::setXY(int x, int y){
	this->x = x;
	this->y = y;
}
