#include <ncurses>

class Display{
private:
    const int height;   //default: 80
    const int width;    //default: 40

public:
    // Constructors and Destructors
    Display(int height, int width);
    Display();
    ~Display(); 

    // Display Output
    void printLevel (char **level ); 

    /**
     *  int getch(void) is provided by the API
     *  The return values are macros defined in ncurses.h
     *  all starting with KEY_
     *      e.g. KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT,
     *           KEY_EXIT, KEY_SPACE, KEY_RETURN
    **/
};
