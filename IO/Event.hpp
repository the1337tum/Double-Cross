/**	Header file for Event class
 *
 */

#ifndef EVENT_H_
#define EVENT_H_

// Identifiers (ID) - all other objects are > 2.
#define NOBODY 0
#define KEYBOARD 1
#define PLAYER 2

class Event {
protected:
    Rect diffArea;      // The area the event occured over
    CharMap *owner;     // The character map assosiated with the event

public:
    const int identifier; // Who the event belongs to
    
    Event(); 
    Event( Event *new_event );
    virtual ~Event();

    void trigger() = 0; // Prints to level and triggers new events based on collisions.
    void update(Event *new_event) = 0;  // Merge new events to exsisting event
};

enum moveDir { left, up, right, down };
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

enum rotateDir { clock, counter };
class EventRotate: public Event {
private:
    Direction direction;

public:
    EventRotate( EventRotate *copy ); // Copies all new_event's datafields into it's own.
    EventRotate( Direction direction, int identifier, Team team, CharMap *charMap );
    ~EventRotate(void);
};

class EventShoot: public Event {
    
};

#endif /* EVENT_H_ */
