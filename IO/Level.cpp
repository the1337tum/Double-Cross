/**	Level
 *	More detailed documentation can be found in the header file, Level.h
 */

#include "Level.hpp"
#include <ncurses.h>

using namespace std;

// Private Collision Method: returns ID of who it collided with - 1 for the map itself.
int Level::collision(CharMap *object) {
    // Calculating object hits to reduce testing area, and double testing.
    if (levelCollision(object)) {
        if (objectCollision(object))
            return (*object).getID();
        return 1;
    }
    return 0;
}

int inline Level::levelCollision(CharMap *object) {
    for (int row = (*object).getLocation()->start_y
        ;row < (*object).getLocation()->rows
	;row++) 
        for (int col = (*object).getLocation()->start_x
            ;col < (*object).getLocation()->cols
            ;col++)
            if(window[row][col] =! ' ')
                return 1;
    
    return 0;
}

int inline Level::objectCollision(CharMap *object) {
    for (int count = 0; count < objs_index; count++) {
        if (object == &objs[count]) // Objects can't collide with themselves
            return 0;
         
        Rect location = new Rect(objs[count].getLocation());
        if (object->location.start_x > location.start_x + location.cols 
        || (object->location.start_y > location.start_y + location.rows) )
            if (location.start_x > object->location.start_x + object->location.cols 
            || (location.start_y > object->location.start_y + object->location.rows) )
                return object.ID;
    }
    
    return 0;
}

// Constructors and destructors
Level::Level() {
	arrayIndex = 0;
	printw("No map provided!\n");
}

// Save and load rely on location for replaying
Level::Level(char **map, Rect location) {
	arrayIndex = 0;
	for (int row = location->start_y; row < location->rows; row++)
		window[row] = map[row];
}

// Accessors
Rect Level::getLocation() {
    return location;
}

CharMap const *** Level::getObjects() {
    return objs;
}

// Mutators
int Level::addObject(CharMap const *object) {
    if (collision(object))
        return 0;
    
    char *** new_map = map.getMap();
    for (int x = 0; x < new_area->cols; x++) 
        for (int y = 0; y < new_area->rows; y++)
            window[x + new_area->start_x][y + area->start_y] = new_map*[x][y];
    
    return ++arrayIndex;
}

void Level::delObject(CharMap const *map) {
    for (int x = 0; x < map.location->cols; x++)
        for (int y = 0; y < map.location->rows; y++)
            window[x + map.location->start_x][y + map.location->start_y] = ' ';
    
    arrayIndex -= 1;
}

// Interface method
void Level::printLevel() {
    for (int row = 0; row < location->rows; row++)
        printw(level[row]);
    refresh();
    }
}

