/** Header file for Person class
 *
 *  A Person object is an abstract Movable object that provides abstraction for
 *  the Enemy and Avatar classes.
 */

#ifndef PERSON_H_
#define PERSON_H_
#include "Movable.hpp"

class Person: public Movable
{
public:
	// Constructor with parameters
	Person(int p_x, int p_y, int rows, int cols, char ***p_map);

	// Copy constructor
	// TODO

	// Assignment operator
	Person & operator=(Person const &);

	// Destructor
	virtual ~Person();
};

#endif /* PERSON_H_ */
