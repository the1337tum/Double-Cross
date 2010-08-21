/**	Header file for Level class - Map and datastructure abstraction layer. 
 *      This is the main interface with IO. 
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

#define MAX_OBJECTS 100 // The maximum number of objects in the event queue.
// Identifiers (ID) - all other objects are > 2.
// NOBODY 0
// KEYBOARD 1
// PLAYER 2

public class Level {
private:
    static char **level;         // Char array for the level.
    Rect location;               // Location of the window.
    CyclicArray<char *> window;  // Sliding display window.
    map<int, CharMap *> objects; // Objects currently on the level: ID -> locaion.

    int collision(int ID, CharMap *object); // Cannot collide with itself.

public:
    Level();
    Level(char **map, Rect window_area);
    ~Level();
   
    // Accessors
    Rect getLocation(); // The location of the sliding window.
    map<int, CharMap *> *getObjects(); // Pointer to the hashed objects. 

    // Mutators
    int addObject(int ID, CharMap *map); // True if success, false if failed.
    int moveObject(CharMap *event);      // Moves an object on the map.
    
    void printLevel();  // Interfaces with ncurses to print the level.
};

#endif /* LEVEL_H_ */
