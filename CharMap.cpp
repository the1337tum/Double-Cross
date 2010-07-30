#include "stdafx.h"
#include "CharMap.h"
#include <iostream>

CharMap::CharMap( int start_x, int start_y, int rows, int cols, char **map )
{
	(*this).num_rows = rows;
	(*this).num_cols = cols;
	(*this).start_x = start_x;
	(*this).start_y = start_y;
	(*this).map = map;
}

CharMap::CharMap( CharMap *new_charMap )
{
	CharMap( (*new_charMap).start_x,  (*new_charMap).start_y,
			 (*new_charMap).num_rows, (*new_charMap).num_cols,
			 (*new_charMap).map );
}

void CharMap::replace( CharMap *copy )
{
	for( int row = 0; row < num_rows && row < (*copy).num_rows; row++ )
		for( int col = 0; col < num_cols && col < (*copy).num_cols; col++ )
			(*this).map[row][col] = (*copy).map[row][col];
}

int CharMap::collision( CharMap *copy)
{
	for( int row = 0; row < num_rows; row++ )
		for( int col = 0; col < num_cols; col++ )
			if( (*this).map[row][col] != ' ' )
				return 0;
	return 1;
}

void CharMap::print()
{
	for ( int row = 0; row < (*this).num_rows; row++ )
		printf( "%s\n", map[row] );
}

/* #################################################################### */
/*	Methods not particular to the map, but used for the 2d char array.	*/
/* #################################################################### */

// creates a contiguious char array
char **char_array_alloc( int rows, int cols )
{
	char **row_ptr;  //row pointer
	char *array_ptr; //contiguious array pointer
	int index;

	array_ptr = (char*) malloc( rows * cols * sizeof(char) );
	if( array_ptr == NULL )
	{
		puts("\nFailure to allocate room for the array");
		exit(0);
	}

	row_ptr = (char**) malloc( rows * sizeof(row_ptr) );
	if ( row_ptr == NULL )
	{
		puts("\nFailure to allocate room for pointers");
		exit(0);
	}

	/* Point the pointers */
	for ( index = 0; index < rows; index++ )
	{
		row_ptr[index] = array_ptr + (index * cols);
	}

	return row_ptr;
}

// Testing for how pointers are incrimented
void char_array_test( char **charMap, int rows )
{
	int row;

	printf("\n\nTesting for how pointers are incrimented:");
	printf("\n\nIndex   Pointer(hex)  Diff.(dec)");

	for ( row = 0; row < rows; row++ )
	{
		printf("\n%d         %p", row, charMap[row]);
		if (row > 0)
			printf("              %d", (charMap[row] - charMap[row-1]));
	}
}