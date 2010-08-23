/*	Test the Display object * *	Tests:
 *	1)  Construct a Display object with parameters.
 *		FAIL
 *      2)  Test that ncruses initilises correctly.
 *              
 *	2)  Destruct a Display object.
 *		FAIL
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../IO/Display.hpp"

using namespace std;

int main() {

    /**	Test 1
     *  Initilise screen, keypad and ncurses.
    **/
    Display display = new Display();

    /** Test 2
     *  Test that screen is initilised correctly
    **/
    printw("hello, world!");

    /** Test 3
     *  Destruct object and display
    **/
    delete display;
    return 0;
}

