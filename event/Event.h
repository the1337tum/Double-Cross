/**	Header file for Event class
 *
 *	TODO Write a brief summary of what an Event object does and is used
 *	for.
 *	TODO Split this into event types - event types spawn from this event class.
 *	Make better OO model, for sure!
 */

#ifndef EVENT_H_
#define EVENT_H_
#include "mylib.h"
#include "CharMap.h"

enum EventType { move, rotate, shoot };

class Event {
protected:
    Rect diffArea;		// The area the event occured over
    CharMap *charMap;	// The character map assosiated with the event

public:
    const EventType type;	// The type of event (subclass)
    const int identifier;	// Who the event belongs to
    const Team team;		// For friendly fire

    Event( EventType type, int x, int y, int identifier, Team team, CharMap *charMap );
    Event( Event *new_event ); // Shallow copy
    Rect *changedArea(); // Returning a pointer is slightly dangerous. Will assess preformance gains vs. safty later.
    ~Event();
};

class EventMove: public Event {
private:
    int move_x;
    int move_y;

public:
    EventMove( EventMove *copy ); // Copies all new_event's datafields into it's own.
    EventMove( int move_x, int move_y, int identifier, Team team, CharMap *charMap );
    ~EventMove(void);

    /*	Owners need not be the same in these operations, so remain untouched.	*/
    void move( Event toAdd );
    void scale_move( int x, int y );
};

class EventRotate: public Event {
private:
    Direction direction;

public:
    EventRotate( EventRotate *copy ); // Copies all new_event's datafields into it's own.
    EventRotate( Direction direction, int identifier, Team team, CharMap *charMap );
    ~EventRotate(void);
};

#endif /* EVENT_H_ */
