#include <ncurses>

enum KeyPressed {
    keyEsc,
    keySpace,
    keyReturn,
    keyLeft,
    keyUp,
    keyRight,
    keyDown
};

class DisplayIO{
private:
    const int height;   //default: 80
    const int width;    //default: 40

public:
    // Constructors and Destructors
    DisplayIO(int height, int width) : height( height ), width( width ) {
        initscr();              // Start curses mode
        nodelay(stdscr, TRUE);  // Don't wait for input on getch()
        keypad(stdscr, TRUE);   // Get function keys (F1 and arrows)
        cbreak();               // Read raw input - except Ctrl-C etc.
        noecho();               // Don't echo() for getch
    }

    DisplayIO() : DisplayIO( 80, 40 ) { /* Default Constructor */ }

    ~DisplayIO() {
        endwin();   // End curses mode
    }

    // Display Output
    void printLevel (char **level ) {
        for (int row = 0; row < height; row++)
            printw( level[row] );
        refresh();
    }

    /**
     *  int getch(void) is provided by the API
     *  The return values are macros defined in ncurses.h
     *  all starting with KEY_
     *      e.g. KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT,
     *           KEY_EXIT, KEY_SPACE, KEY_RETURN
    **/
}
