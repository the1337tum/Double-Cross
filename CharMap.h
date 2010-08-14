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
    int cols;   //end_x = start_x + cols 
    int rows;   //end_y = start_y + rows 
};

class CharMap {
private:
    Rect location;
    char ***map; // A pointer to a static 2d char array.

public:
    CharMap( int start_x, int start_y, int rows, int cols, char ***map );
    CharMap( CharMap *new_charMap ); // Stack variables are copied. Dynamic variables are not.
    virtual ~CharMap(void);
    
    // Operators
    CharMap &operator=(CharMap const &);
    
    // Accessors
    Rect getLocation();
    char*** getMap();
    
    // Mutators
    // TODO Define Direction
    void move(Direction direction);
    void replaceMap( CharMap *replacement );
};

#endif /* CHARMAP_H_ */

