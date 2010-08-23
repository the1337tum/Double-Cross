/**	CharMap
 *	More detailed documentation can be found in the header file,
 *	CharMap.h
 */

#include <stdio.h>
#include "CharMap.hpp"

// Constructor with parameters
CharMap::CharMap( int start_x, int start_y, int cols, int rows, char ***map ) {
	location.start_x = start_x;
	location.start_y = start_y;
	location.cols = cols;
	location.rows = rows;
	this->map = map;
	printf("Constructing CharMap object.\n");	// debug
}

// Copy constructor
CharMap::CharMap(const CharMap &c) {
	location.start_x = c.location.start_x;
	location.start_y = c.location.start_y;
	location.cols = c.location.cols;
	location.rows = c.location.rows;
	this->map = c.map;
	printf("Copy constructing CharMap object.\n");	// debug
}

CharMap::~CharMap() { 
	printf("Destructing CharMap object.\n");	// debug
}

CharMap& CharMap::operator=(CharMap const &c) {
	if (&c != this) {
		// Allocate new memory
		char *** new_map = c.map;

		// Deallocate old memory
		delete map;

		// Assign the new memory to the object
		location.start_x = c.location.start_x;
		location.start_y = c.location.start_y;
		location.cols = c.location.cols;
		location.rows = c.location.rows;
		map = new_map;
	}
	printf("Assignment copying CharMap object.\n");	// debug
	return *this; // For assignment chaining.
}

Rect *CharMap::getLocation() { return &(this->location); }

char *** CharMap::getMap() { return this->map; }

int CharMap::getID() { return this->ID; }

void CharMap::move(Direction direction) {
	switch (direction) {
		case UP:
			location.start_y++;
			break;
		case RIGHT:
			location.start_x++;
			break;
		case DOWN:
			location.start_y--;
			break;
		case LEFT:
			location.start_x--;
			break;
		default:
			perror("Error: Illegal CharMap::move move.");
	}
}

void CharMap::replaceMap(CharMap *replacement) {
	map = (*replacement).map;
}
