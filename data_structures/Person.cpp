/**	Person
 *	More detailed documentation can be found in the header file, Person.h
 */

#include <stdio.h>
#include "Person.hpp"
#include "Movable.cpp"

// Constructor with parameters
Person::Person(int p_x, int p_y, int rows, int cols, char ***p_map) :
	Movable(p_x, p_y, rows, cols, p_map)
{
	printf("Constructing Person object.\n");	// debug
}

// Copy constructor
// TODO

// Assignment operator
Person& Person::operator=(Person const &p)
{
	if (&p != this)
	{
		map = p.map;
	}
	printf("Shallow copying Person object.\n");	// debug
	return *this;
}

// Destructor
Person::~Person() {
	printf("Destructing Person object.\n");	//debug
}
