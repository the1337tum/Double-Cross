/** Header file for Enemy class
 *
 *	A Enemy object is a Person object that the player needs to kill or get
 *	past in order to win the game.
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Person.hpp"

class Enemy: public Person
{
public:
	// Constructor with parameters
	Enemy(int p_x, int p_y, int rows, int cols, char ***p_map);

	// Copy constructor
	// TODO

	// Assignment operator
	Enemy & operator=(Enemy const &);

	// Destructor
	virtual ~Enemy();
};

#endif /* ENEMY_H_ */
