/**	Header file for Level class
 *
 *	The Level object is responsible for:
 *	1)  Detecting collisions between CharMaps and/or the Level.
 *	2)  Printing to the display if no collision occurs.
 *	3)  Deleting the appropriate objects if a collision is detected.
 **/

#ifndef LEVEL_H_
#define LEVEL_H_

#define MAX_OBJECTS 100 // The maximum number of objects in the event queue.

public class Level {
private:
    static char **level;
    Queue<CharMap *, MAX_OBJECTS> NPCs;
    CyclicArray<char *> window; // The sliding window.
    Rect location; // The current location of the window

    int collision(CharMap *map);
public:
    Level() {
        System.err.printf("No map provided!");
    }

    Level(CharMap *new_map) {
        level = new_map.getMap();
        location = new_map.getLocation();
        for (int row = 0; row < location->rows; row++) {
            window[row] = level[row];
        }
    }

    ~Level();
   
    // True if success, false if failed 
    int printMap(CharMap *map) {
        return collision() ? 0 : 1;
    }

    int moveMap(Event ){}

    testObjects();
};

#endif /* LEVEL_H_ */
