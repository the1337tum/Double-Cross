/**	Header file for Level class
 *      Abstraction Level:  NCurses <--> Level <--> Events
 *
 *	The Level object is responsible for:
 *	1)  Detecting collisions between CharMaps and/or the Level.
 *	2)  Printing to the display if no collision occurs.
 *	3)  Deleting the appropriate objects if a collision is detected.
 **/

#ifndef LEVEL_H_
#define LEVEL_H_
    
/* This is the same class you'd use for the concurrent version 
        - just adding an event queue and fork and loop in the constructor. */

#include <map>
#include "../AI/data_structures/CharMap.hpp"

#define WINDOW_SIZE 80
#define MAX_OBJECTS 100 // The maximum number of objects in the event queue.
// Identifiers (ID) - all other objects are > 2.
// NOBODY 0
// KEYBOARD 1
// PLAYER 2

class Level {
private:
	static char **level;            // Char array for the level.
	Rect location;                  // Location of the window.
	// TODO Implement CyclicArray<char *>
	CyclicArray<char *, WINDOW_SIZE> window;     // Sliding display window.
	CharMap objects [MAX_OBJECTS];   // Array of the objects
	int arrayIndex; // TODO Initialise arrayIndex

	int collision(CharMap *object); // Cannot collide with itself.
	int inline levelCollision(CharMap *object);
	int inline objectCollision(CharMap *object);

public:
	// Default constructor
	Level();

	// Constructor with parameters
	Level(char **map, Rect location);

	// Destructor
	virtual ~Level();
     
	// Accessors
	Rect getLocation(); // The location of the sliding window.
	CharMap ***getObjects(); // Pointer (*) to the 2d array (**). 
    
	// Mutators
	int addObject(CharMap const *map); // True if success, false if failed.
	void delObject(CharMap const *map);// Removes an object on the map.
    
	void printLevel();  // Interfaces with ncurses to print the level.
};

#endif /* LEVEL_H_ */
