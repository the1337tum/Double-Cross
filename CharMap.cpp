/**	CharMap
 *	More detailed documentation can be found in the header file,
 *	CharMap.h
 */

#include "CharMap.h"

// Constructor with parameters
CharMap::CharMap(int rows, int cols, char **p_map) :
	num_rows(rows), num_cols(cols), map(p_map) { }

// Copy constructor
CharMap::CharMap(CharMap const &c) :
	num_rows(c.num_rows), num_cols(c.num_cols), map(c.map) { }

// Assignment operator
CharMap& CharMap::operator=(CharMap const &c)
{
	if (&c != this)
	{
		num_rows = c.num_rows;
		num_cols = c.num_cols;
		map = c.map;
	}
}

// Destructor
CharMap::~CharMap() { }
