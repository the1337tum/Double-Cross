/**
 *  Responsabilities:
 *      Detecting collisions between character maps and/or the level.
 *      Printing to the display if no collision occurs.
 *      Deleting appropriate objects if a collision is detected.
**/


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

