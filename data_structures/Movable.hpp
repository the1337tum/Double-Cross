/** Header file for Movable class
 *
 *  A Movable object is an Collidable object that can move.
 */

#ifndef MOVABLE_H_
#define MOVABLE_H_
#include "Collidable.hpp"

class Movable: public Collidable
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

	// move(Direction)
	virtual int move(Direction direction);
};

#endif /* MOVABLE_H_ */
