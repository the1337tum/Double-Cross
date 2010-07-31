/**	CharMap
 *	More detailed documentation can be found in the header file,
 *	CharMap.h
 */

#include <stdio.h>
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

// char_array_alloc()
char **char_array_alloc(int rows, int cols)
{
	char **row_pointer;
	char *array_pointer;	// Contiguous array pointer
	int i;

	array_pointer = (char*) malloc(rows * cols * sizeof(char));
	if (array_pointer == NULL)
	{
		printf("\nFailure to allocate room for the char array.");
		exit(1);
	}

	row_pointer = (char**) malloc(rows * sizeof(row_pointer));
	if (row_pointer == NULL)
	{
		printf("\nFailure to allocate room for pointers.");
		exit(1);
	}

	// Initalise the pointers
	for (i = 0; i < rows; i++)
	{
		row_pointer[i] = array_pointer + (index * cols);
	}

	return row_pointer;
}
