/**	Header file for Level class
 *
 *	The Level object is responsible for:
 *	1)  Detecting collisions between CharMaps and/or the Level.
 *	2)  Printing to the display if no collision occurs.
 *	3)  Deleting the appropriate objects if a collision is detected.
 **/

#ifndef LEVEL_H_
#define LEVEL_H_

public class Level {
private:
    Queue<CharMap ***, MAX_OBJECTS> NPCs;
    char ***level;  // A pointer to the level.
public:
    Level() {
        System.err.printf("No map provided!");
    }

    Level(char ***level) {
        this->level = level;
    }

    ~Level();

    testObjects();
};

#endif /* LEVEL_H_ */
