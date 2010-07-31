/**	Collidable
 *	More detailed documentation can be found in the header file,
 *	Collidable.h
 */

#include "Collidable.h"

// Constructor with parameters
Collidable::Collidable(int p_x, int p_y, int rows, int cols, char **p_map) :
	x(p_x), y(p_y), num_rows(rows), num_cols(cols), map(p_map) { }

// Copy constructor
Collidable::Collidable(Collidable const &c) :
	x(c.x), y(c.y), num_rows(c.num_rows), num_cols(c.num_cols), map(c.map)
{ }

// Assignment operator
Collidable& Collidable::operator=(Collidable const &c)
{
	if (&c != this)
	{
		x = c.x;
		y = c.y;
		num_rows = c.num_rows;
		num_cols = c.num_cols;
		map = c.map;
	}
}

// Destructor
Collidable::~Collidable() { }

// draw()
//int draw() { }

// collide(Collidable c1)
//int collide(Collidable c1) { }
