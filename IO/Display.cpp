#include "Display.hpp"

using namespace std;

Display::Display(int height, int width) : height(height), width(width) {
    initscr();              // Start curses mode
    nodelay(stdscr, TRUE);  // Don't wait for input on getch()
    keypad(stdscr, TRUE);   // Get function keys (F1 and arrows)
    cbreak();               // Read raw input - except Ctrl-C etc.
    noecho();               // Don't echo() for getch
}

Display::Display() : height(80), width(40) { /* Default Constructor */ }

Display::~Display() {
    endwin();   // End curses mode
}

