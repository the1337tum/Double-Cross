/**	Projectile
 *	More detailed documentation can be found in the header file, 
 *	Projectile.h
 */

#include <stdio.h>
#include "Projectile.hpp"
#include "Movable.cpp"

// Constructor with parameters
Projectile::Projectile(int p_x, int p_y, int rows, int cols, char ***p_map) :
	Movable(p_x, p_y, rows, cols, p_map)
{
	printf("Constructing Projectile object.\n");	// debug
}

// Copy constructor
// TODO

// Assignment operator
Projectile& Projectile::operator=(Projectile const &p)
{
	if (&p != this)
	{
		map = p.map;
	}
	printf("Shallow copying Projectile object.\n");	// debug
	return *this;
}

// Destructor
Projectile::~Projectile() {
	printf("Destructing Projectile object.\n");	//debug
}
