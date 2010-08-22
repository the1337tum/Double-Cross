/**	Header file for Avatar class
 *
 *	An Avatar object is a Person object that the player controls. The
 *	player moves the Avatar object and commands the Avatar object to use
 *	its weapon.
 */

#ifndef AVATAR_H_
#define AVATAR_H_
#include "Person.hpp"

class Avatar: public Person
{
public:
	// Constructor with parameters
	Avatar(int p_x, int p_y, int rows, int cols, char ***p_map);

	// Copy constructor
	// TODO

	// Assignment operator
	Avatar & operator=(Avatar const &);

	// Destructor
	virtual ~Avatar();
};

#endif /* AVATAR_H_ */
