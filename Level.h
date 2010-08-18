/**	Header file for Level class
 *
 *	The Level object is responsible for:
 *	1)  Detecting collisions between CharMaps and/or the Level.
 *	2)  Printing to the display if no collision occurs.
 *	3)  Deleting the appropriate objects if a collision is detected.
 **/

#ifndef LEVEL_H_
#define LEVEL_H_

#include <map>

#define MAX_OBJECTS 100 // The maximum number of objects in the event queue.
// Identifiers (ID) - all other objects are > 2.
// NOBODY 0
// KEYBOARD 1
// PLAYER 2

public class Level {
private:
    static char **level;        // Char array for the level.
    Rect location;              // Location of the window.
    CyclicArray<char *> window; // Sliding display window.
    map<int, Rect> objects;     // Objects currently on the level: ID -> locaion.

    int collision(int ID, Rect area); // Cannot collide with itself.

public:
    Level();
    Level(char **map, Rect window_area);
    ~Level();
   
    // True if success, false if failed 
    int addObject(int ID, CharMap *map); 
    void printLevel();
    int moveMap(CharMap *event); 

    testObjects();
};

#endif /* LEVEL_H_ */
