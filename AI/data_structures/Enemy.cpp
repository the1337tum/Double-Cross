/**	Enemy
 *	More detailed documentation can be found in the header file, Enemy.h
 */

#include <stdio.h>
#include "Enemy.hpp"
#include "Person.cpp"

// Constructor with parameters
Enemy::Enemy(int p_x, int p_y, int rows, int cols, char ***p_map) :
	Person(p_x, p_y, rows, cols, p_map)
{
	printf("Constructing Enemy object.\n");	// debug
}

// Copy constructor
// TODO

// Assignment operator
Enemy& Enemy::operator=(Enemy const &e)
{
	if (&e != this)
	{
		map = e.map;
	}
	printf("Shallow copying Enemy object.\n");	// debug
	return *this;
}

// Destructor
Enemy::~Enemy() {
	printf("Destructing Enemy object.\n");	//debug
}
