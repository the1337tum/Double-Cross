/**	Header file for CharMap class
 *	A CharMap object is basically just a glorified 2D char array.
 *	When a graphical object, such as a Collidable object, is created, it
 *	needs a CharMap to store the Unicode characters which will be used to
 *	draw its graphical image in the terminal. This 2D array stores the
 *	image and returns its contents when the object is called to be drawn.
 */

#ifndef CHARMAP_H_
#define CHARMAP_H_

class CharMap
{
public:
	int num_rows;	// Number of rows in the character map.
	int num_cols;	// Number of columns in the character map.
	char **map;	// A pointer to a static character map.

	// Constructor with parameters
	CharMap(int rows, int cols, char ** p_map);

	// Copy constructor
	CharMap(CharMap const &);

	// Assignment operator
	CharMap &operator=(CharMap const &);

	// Destructor
	virtual ~CharMap();

	// char_array_alloc()
	// Allocates memory for the CharMap
	char **char_array_alloc(int rows, int cols);
};

#endif /* CHARMAP_H_ */
