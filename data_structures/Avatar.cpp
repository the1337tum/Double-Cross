/**	Avatar
 *	More detailed documentation can be found in the header file, Avatar.h
 */

#include <stdio.h>
#include "Avatar.hpp"
#include "Person.cpp"

// Constructor with parameters
Avatar::Avatar(int p_x, int p_y, int rows, int cols, char ***p_map) :
	Person(p_x, p_y, rows, cols, p_map)
{
	printf("Constructing Avatar object.\n");	// debug
}

// Copy constructor
// TODO

// Assignment operator
Avatar& Avatar::operator=(Avatar const &a)
{
	if (&a != this)
	{
		map = a.map;
	}
	printf("Shallow copying Avatar object.\n");	// debug
	return *this;
}

// Destructor
Avatar::~Avatar() {
	printf("Destructing Avatar object.\n");	//debug
}
