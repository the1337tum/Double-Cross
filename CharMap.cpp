/**	CharMap
 *	More detailed documentation can be found in the header file,
 *	CharMap.h
 */

#include <stdio.h>
#include "CharMap.h"

CharMap::CharMap( int start_x, int start_y, int rows, int cols, char ***map ) {
    location.start_x = start_x;
    location.start_y = start_y;
    location.rows = rows;
    location.cols = cols;
    this->map = map;
}

// I'm getting an error saying that CharMap is not the superclass of CharMap.
// Is the constructor supposed to have another constructor inside it?
CharMap::CharMap( CharMap *new_charMap ) {
    CharMap( new_charMap->location.start_x,  
             new_charMap->location.start_y,
             new_charMap->location.rows,
             new_charMap->location.cols, 
             new_charMap->map );
}

CharMap::~CharMap(void) { /* Nothing to clean up */ }

CharMap& CharMap::operator=(CharMap const &c) {
    if (&c != this) {
	location.start_x = c.location.start_x;
	location.start_y = c.location.start_y;
	location.rows = c.location.rows;
	location.cols = c.location.cols;
	map = c.map;
    }
}

Rect CharMap::getLocation() { return location; }

char ***getMap() { return map; }

void CharMap::move( Direction direction ) {
    switch(direction):
    case up:
        location.start_y++;
        break;
    case right:
        location.start_x++;
        break;
    case down:
        location.start_y--;
        break;
    case left:
        location.start_x--;
        break;
    default:
        System.err.printf("CharMap::move has gone awry.");
}

void CharMap::replaceMap( CharMap ***replacement ) {
	map = replacement;
}

