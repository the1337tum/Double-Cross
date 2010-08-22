/**	Movable
 *	More detailed documentation can be found in the header file, Movable.h
 */

#include <stdio.h>
#include "Movable.hpp"
#include "Collidable.cpp"

// Constructor with parameters
Movable::Movable(int p_x, int p_y, int rows, int cols, char ***p_map) :
	Collidable(p_x, p_y, rows, cols, p_map)
{
	printf("Constructing Movable object.\n");	// debug
}

// Copy constructor
// TODO

// Assignment operator
Movable& Movable::operator=(Movable const &m)
{
	if (&m != this)
	{
		map = m.map;
	}
	printf("Shallow copying Movable object.\n");	// debug
	return *this;
}

// Destructor
Movable::~Movable() {
	printf("Destructing Movable object.\n");	//debug
}

// move(Direction)
int Movable::move(Direction direction) {
	(*map).move(direction);
	return 0;
}
