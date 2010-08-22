/**	Collidable
 *	More detailed documentation can be found in the header file,
 *	Collidable.h
 */

#include <stdio.h>
#include "Collidable.hpp"
#include "CharMap.cpp"

// Constructor with parameters
Collidable::Collidable(int p_x, int p_y, int rows, int cols, char ***p_map)
//	x(p_x), y(p_y), num_rows(rows), num_cols(cols), map(p_map) { }
{
	map = new CharMap(p_x, p_y, rows, cols, p_map);
	printf("Constructing Collidable object.\n"); // debug
}

// Copy constructor
Collidable::Collidable(Collidable const &c)
//	x(c.x), y(c.y), num_rows(c.num_rows), num_cols(c.num_cols), map(c.map)
{
	printf("Deep copying Collidable object.\n"); // debug
}

// Assignment operator
Collidable& Collidable::operator=(Collidable const &c)
{
	if (&c != this)
	{
		map = c.map;
	}
	printf("Shallow copying Collidable object.\n"); // debug
	return *this;
}

// Destructor
Collidable::~Collidable() {
	delete map;
	printf("Destructing Collidable object.\n"); // debug
}

// draw()
//int Collidable::draw() {
//	return 0;
//}

// collide(Collidable * c1)
//int collide(Collidable * c1) { }
