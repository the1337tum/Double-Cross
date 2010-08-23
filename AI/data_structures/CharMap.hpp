/**	Header file for CharMap class
 *
 *	A CharMap object is simply a map with a position.
 *	All debug output should be printed to stderr, not printw.
 *	All other official display methods should be printed to the level
 *	buffer, not the display. This is done for collision detection and
 *	efficiency.
 */

#ifndef CHARMAP_H_
#define CHARMAP_H_

struct Rect {
	int start_x; 
	int start_y;
	int cols;	//end_x = start_x + cols 
	int rows;	//end_y = start_y + rows 
};

enum Direction { UP, DOWN, LEFT, RIGHT };

class CharMap {
protected:
	Rect location;
	char **map;	// A pointer to a static 2d char array.
	int ID;		// Collision ID

public:
	// Constructor with parameters
	CharMap(int start_x, int start_y, int cols, int rows, char **map);

	// Copy constructor
	CharMap(CharMap const &);

	// Assignment operator
	CharMap &operator=(CharMap const &);

	// Destructor
	virtual ~CharMap(void);
    
	// Accessors
	Rect *getLocation();
	char **getMap();
	int getID();
    
	// Mutators
	void move(Direction direction);
	void replaceMap(char **); // TODO Test
};

#endif /* CHARMAP_H_ */
