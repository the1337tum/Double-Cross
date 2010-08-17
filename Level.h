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
    Rect location; // The current location of the window
    CyclicArray<char *> window; // The sliding window.
    Queue<Char *, MAX_OBJECTS> objects;

    int collision(Rect area);

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
    int addObject(CharMap *map) {
        if (collision(map.getLocation()))
            return 0;
        
        objects.put(map);

        return 1;
    }
    
    void printLevel() {
        for (int row = 0; row < location->rows; row++)
            printw( level[row] );
        refresh();
    }

    int moveMap(CharMap *event) {
        return collision(event.getLocation())
    }

    testObjects();
};

#endif /* LEVEL_H_ */
