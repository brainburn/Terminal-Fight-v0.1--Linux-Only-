/*
 * enemy.cpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 */

#include "enemy.hpp"


//Implement the way in which enemy takes damage
void
Enemy::takeDamage(Player* unit){
	Map         *map = Map::getMap();
	stringstream hud;

	setHealth(getHealth() - unit->getAttack() + getDefense());

	//Update the HUD (human user display)
	unit->experience += unit->getAttack();
	hud << "Enemy Life: " << getHealth() << "		Your Life: " << unit->getHealth() << endl;
	hud << "Enemy Defense: " << getDefense() << "	Your Defense: " << unit->getDefense() << endl;
	hud << "Enemy Attack: " << getAttack() << "	Your Attack: " << unit->getAttack() << endl;
	map->setHud(hud.str());

	//If enemy took more that 50 damage, make player level up
	if(unit->experience >= 50){
		unit->levelUp();
	}
}

//Get the player's coordinates.
//Randomly choose which way to advance towards it,
//and move. This also implements attacking the
//player (moving into it)
void
Enemy::findPlayer(){
	Player *p = Player::getPlayer(0, 0);
	Map *m = Map::getMap();
	int toX = p->x;
	int toY = p->y;
	srand(time(NULL));

	if(rand()%2 == 0)
		if(this->x <= toX){
			moveRight(m);
		}
		else{
			moveLeft(m);
		}
	else{
		if(this->y <= toY){
			moveDown(m);
		}
		else{
			moveUp(m);
		}
	}
}

void
Enemy::die(){
	Map *map = Map::getMap();
	map->setHud("Enemy defeated!");
	Entity *b = new Entity();
	map->setMap(this->x, this->y, b);
	delete this;
	cout << map->printmap();
}

//Places Enemy on the map.
void
Enemy::putUnit(Map *m){
	//If whatever is at this point is not
	//me, remove it, and put me there.
	if(m->getBox(this->x, this->y) != this){
		delete m->getBox(this->x, this->y);
		m->setMap(this->x, this->y, this);

		//Clear the screen and redisplay changes
		cout << "\033[2J\033[1;1H";
		cout << m->printmap();
	}
}

void
Enemy::moveTo(Map *m, int x, int y){
	//Make sure that player is constrained by
	//map, and check for collisions.
	if((y < MAP_HEIGHT && y >= 0) &&
	   (x < MAP_WIDTH && x >= 0)&&
	   !m->getBox(x, y)->collide(this)){

		//Replace the empty spot behind me by a piece of Floor
		Floor *b = new Floor(this->x, this->y);

		//Move unit
		m->setMap(this->x, this->y, b);
		this->setXY(x, y);
		putUnit(m);
	}
	else{
		putUnit(m);
	}
}

//Makes the Enemy face to the left, and moves it
void
Enemy::moveLeft(Map *m){
	this->skin[0][0]="|";
	this->skin[0][2]=" ";
	this->skin[1][0]="+";
	this->skin[1][2]="\\";
	moveTo(m, this->x - 1,this->y);
}

//Makes the Enemy face to the right, and moves it
void
Enemy::moveRight(Map *m){
	this->skin[0][0]=" ";
	this->skin[0][2]="|";
	this->skin[1][0]="/";
	this->skin[1][2]="+";
	moveTo(m, this->x + 1,this->y);
}

//Move up
void
Enemy::moveUp(Map *m){
	moveTo(m, this->x,this->y - 1);
}

//Move down
void
Enemy::moveDown(Map *m){
	moveTo(m, this->x,this->y + 1);
}

//What happens when someone bumps into the enemy
bool
Enemy::collide(Entity* unit){
	if(unit->type=="player"){
		Player *p = Player::getPlayer(0,0);
		takeDamage(p);
	}
	return true;
}
