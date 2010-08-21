/**	Level
 *	More detailed documentation can be found in the header file, Level.h
 */

#include "Level.h"
#include <ncurses>

using namespace Level

// Private Collision Method: returns ID of who it collided with - 1 for the map itself.
const int collision(CharMap *object) {
    // Calculating object hits to reduce testing area, and double testing.
    if (levelCollision(CharMap *object)) {
        if (objectCollision(CharMap *object))
            return object.ID;
        return 1;
    }
    return 0;
}

int inline levelCollision(CharMap *object) {
    
    for (int row = object.location->start_x )
}

int inline objectCollision(CharMap *object) {
    for ()
}

// Constructors and destructors
Level() {
    printw("No map provided!\n");
}

// Save and load rely on location for replaying
Level(char **map, Rect location) {
    for (int row = location->start_y; row < location->rows; row++)
        window[row] = map[row];
}

// Accessors
Rect getLocation() {
    return location;
}

map<int, CharMap *> *getObjects() {
    return objects;
}

// Mutators
int addObject(CharMap *object) {
    if (collision(object))
        return 0;
    
    char *** new_map = map.getMap();
    for (int x = 0; x < new_area->cols; x++) 
        for (int y = 0; y < new_area->rows; y++)
            window[x + new_area->start_x][y + area->start_y] = new_map*[x][y];

    return 1;
}

int delObject(CharMap *map) {
    for (int x = 0; x < map.location->cols; x++)
        for (int y = 0; y < map.location->rows; y++)
            window[x + map.location->start_x][y + map.location->start_y] = ' '; 
}

// Interface method
void printLevel() {
    for (int row = 0; row < location->rows; row++)
        printw(level[row]);
    refresh();
    }
}

