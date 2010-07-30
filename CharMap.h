#pragma once

class CharMap
{
public:
	int num_rows; // Number of rows
	int num_cols; // Number of cols
	int start_x; // Start co-ordinate (printers co-ordinates)
	int start_y; // End co-ordinate (printers co-ordinates)
	char **map;	// A pointer to a static character map.

	CharMap(int start_x, int start_y, int rows, int cols, char **map);
	CharMap(CharMap *new_charMap); // Copies all new_charMap's datafields into it's own.
	// No destructors: clean up after your own mess, slackass.

	void print(); // Prints out the char_map
	void replace( CharMap *copy ); // Replace all overlapping datafields with copy's.
	int collision( CharMap *copy); // Test for a colisions. Checks that all characters in (this) are blank (' ').
};

/*	Methods not particular to the map, but used for the 2d char array.	*/
char **char_array_alloc(int rows, int cols);
void char_array_test(char **charMap, int rows);