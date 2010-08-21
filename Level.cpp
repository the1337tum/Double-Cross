/**	Level
 *	More detailed documentation can be found in the header file, Level.h
 */

#include "Level.h"
#include <ncurses>

using namespace Level

// Constructors and destructors
Level() {
    printw("No map provided!\n");
}

Level(char **map, Rect window_area) {
    level = map
    location = window_area;
    for (int row = location->start_y; row < location->rows; row++) {
        window[row] = level[row];
    }
}

// Accessors
Rect getLocation() {
    return location;
}

map<int, CharMap *> *getObjects() {
    return objects;
}

// Mutators
int addObject(int ID, CharMap *map) {
    Rect new_area = map.getLocation()
    if (collision(ID, new_area))
        return 0;
    
    // Remove the old object
    Rect old_area = objects(ID);
    for (int x = old_area->start_x; x < (old_area->start_x + old_area->cols); x++ ) 
        for (int y = old_area->start_y; y < (old_area->start_y + old_area->rows); y++)
            level[x][y] = ' ';

    char *** new_map = map.getMap();
    for (int x = 0; x < new_area->cols; x++) 
        for (int y = 0; y < new_area->rows; y++)
            level[x + new_area->start_x][y + area->start_y] = new_map*[x][y];

    return 1;
}

int moveMap(CharMap *object) {
    return collision(event.object())
}

// Interface method
void printLevel() {
    for (int row = 0; row < location->rows; row++)
        printw(level[row]);
    refresh();
    }
}

