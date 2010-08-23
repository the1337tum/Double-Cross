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
            return object->getID();
        return 1;
    }
    return 0;
}

int inline Level::levelCollision(CharMap *object) {
    for (int row = object->getLocation()->start_y
        ;row < object->getLocation()->rows
	;row++) 
        for (int col = object->getLocation()->start_x
            ;col < (*object).getLocation()->cols
            ;col++)
            if(window[row][col] =! ' ')
                return 1;
    
    return 0;
}

int inline Level::objectCollision(CharMap *object) {
    for (const Node<CharMap> *node = objs->getFirst(); node != NULL; node = node->next) {
        if (object->getID() == node->ID) // Objects can't collide with themselves
            return 0;
         
        Rect location = new Rect(node->data->getLocation());
        if (object->location.start_x > location.start_x + location.cols 
        || (object->location.start_y > location.start_y + location.rows) )
            if (location.start_x > object->location.start_x + object->location.cols 
            || (location.start_y > object->location.start_y + object->location.rows) )
                return object->getID();
    }
    
    return 0;
}

// Constructors and destructors
Level::Level() {
	printw("No map provided!\n");
}

// Save and load rely on location for replaying
Level::Level(char **map, Rect location) {
    objs = new SLL<CharMap>();
    for (int row = location.start_y; row < location.rows; row++)
        window[row] = map[row];
}

Level::~Level() { delete objs; }

// Accessors
Rect Level::getLocation() {
    return location;
}

// Mutators
int Level::addObject(CharMap *object) {
    if (collision(object))
        return 0;
   
    Rect *area = object->getLocation();
    char **map = object->getMap();
    for (int x = 0; x < area->cols; x++) 
        for (int y = 0; y < area->rows; y++)
            window[x + area->start_x][y + area->start_y] = map[x][y];
    
    return 1;
}

void Level::delObject(CharMap *map) {
    for (int x = 0; x < map->location.cols; x++)
        for (int y = 0; y < map->location.rows; y++)
            window[x + map->location.start_x][y + map->location.start_y] = ' ';
}

// Interface method
void Level::printLevel() {
    for (int row = 0; row < location.rows; row++)
        printw(level[row]);
    refresh();
}

