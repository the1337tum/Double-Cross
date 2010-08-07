#include <ncurses>

class DisplayIO{
private:
    const int height;   //default: 80
    const int width;    //default: 40

public:
    // Constructors and Destructors
    DisplayIO(int height, int width) : height( height ), width( width ) {
        initscr();              // Start curses mode
        cbreak();               // Read raw input - except Ctrl-C etc.
        keypad(stdscr, TRUE);   // Get function keys (F1 and arrows)
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

    // Console Input
    
}
