/**	Event
 *	More detailed documentation can be found in the header file, Event.h
 */

#include "StdAfx.h"
#include "Event.h"
#include "mylib.h"
#include <Windows.h>

using namespace std;

Event( const EventType type, int x, int y, const int identifier, const Team team, CharMap *charMap )
: type( type ), identifier( identifier ), team( team ) {
    
    Rect location = charMap->getLocation();
    this->charMap = charMap; // shallow copy
}


Event( Event *new_event ) 
: type( (*new_event).type ), identifier( (*new_event).identifier ), team( (*new_event).team ) {
    
    diffArea = new_event->diffArea;
    this->charMap = charMap; // shallow copy
}

Event::~Event(void) {
    delete this->charMap;
}

/*
void Event::add( Event toAdd ) {
    x += toAdd.x;
    y += toAdd.y;

}
void Event::subtract( Event toSubtract ) {
    x -= toSubtract.x;
    y -= toSubtract.y;
}

void Event::scale( int x, int y ) {
    (*this).x *= x;
    (*this).y *= y;
}
*/
