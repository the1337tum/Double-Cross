/**	Header file for Collidable class
 *
 *	A Collidable object is an object which represents something that can
 *	collide with something else when the game is being played. This includes
 *	enemies, the avatar, projectiles (bullets) and static obstacles such as
 *	walls and pits. When one Collidable object collides with another
 *	Collidable object, particular reactions occur depending on what kinds of
 *	objects collide. Therefore, the Collidable class will act solely as an
 *	abstract superclass which contains collision and draw functionality
 *	which is inherited by the subclass objects such as Enemy and Obstacle.
 */

#ifndef COLLIDABLE_H_
#define COLLIDABLE_H_
#include "CharMap.hpp"

class Collidable
{
public:
	CharMap * map;

	// Constructor with parameters
	Collidable(int p_x, int p_y, int rows, int cols, char ***p_map);

	// Copy constructor
	Collidable(Collidable const &);

	// Assignment operator
	Collidable & operator=(Collidable const &);

	// Destructor
	virtual ~Collidable();

	// draw()
	// Tells the Level object to draw this Collidable object onto the next
	// frame.
//	virtual int draw();

	// collide(Collidable c1)
	// Determines what happens when this Collidable object collides into
	// another Collidable object. (Explosions, hopefully!)
//	virtual int collide(Collidable * c1);
};

#endif /* COLLIDABLE_H_ */

