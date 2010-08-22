/** Header file for Movable class
 *
 *  A Movable object is an Collidable object that can move.
 */

#ifndef MOVABLE_H_
#define MOVABLE_H_
#include "CharMap.hpp"

class Movable: public CharMap
{
public:
	// Constructor with parameters
	Movable(int p_x, int p_y, int rows, int cols, char ***p_map);

	// Copy constructor
	// TODO

	// Assignment operator
	Movable & operator=(Movable const &);

	// Destructor
	virtual ~Movable();
};

#endif /* MOVABLE_H_ */
