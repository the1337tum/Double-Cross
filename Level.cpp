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
    for (int row = object.location->start_y; row < object.location->rows; row++)
        for (int col = object.location->start_x; col < object.location->cols; cols++)
            if(window[row][col] =! ' ')
                return 1;

    return 0;
}

int inline objectCollision(CharMap *object) {
    for (int count = 0; count < objects.length; count++) {
        if (object == objects[row]) // Objects can't collide with themselves
            return = 0;
      
        Rect location = objects[count].location;
        if (object.location->start_x > location->start_x + location->cols 
        || (object.location->start_y > location->start_Y + location->rows) )
            if (location->start_x > object.location->start_x + object.location->cols 
            || (location->start_y > object.location->start_Y + object.location->rows) )
                return object.ID;
    }
    
    return 0;
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

CharMap const ***getObjects() {
    return objects;
}

// Mutators
int addObject(CharMap const *object) {
    if (collision(object))
        return 0;
    
    char *** new_map = map.getMap();
    for (int x = 0; x < new_area->cols; x++) 
        for (int y = 0; y < new_area->rows; y++)
            window[x + new_area->start_x][y + area->start_y] = new_map*[x][y];

    return ++arrayIndex;
}

void delObject(CharMap const *map) {
    for (int x = 0; x < map.location->cols; x++)
        for (int y = 0; y < map.location->rows; y++)
            window[x + map.location->start_x][y + map.location->start_y] = ' ';

    arrayIndex -= 1;
}

// Interface method
void printLevel() {
    for (int row = 0; row < location->rows; row++)
        printw(level[row]);
    refresh();
    }
}

