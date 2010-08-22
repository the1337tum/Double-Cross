/** Header file for Projectile class
 *
 *  A Projectile object is a Movable object that is created by a Person with
 *  the intention of the Projectile object colliding with another Person.
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_
#include "Movable.hpp"

class Projectile: public Movable
{
public:
	// Constructor with parameters
	Projectile(int p_x, int p_y, int rows, int cols, char ***p_map);

	// Copy constructor
	// TODO

	// Assignment operator
	Projectile & operator=(Projectile const &);

	// Destructor
	virtual ~Projectile();
};

#endif /* PROJECTILE_H_ */
