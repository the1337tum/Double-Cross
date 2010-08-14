/**	Header file for EventQueue class
 *
 *	TODO Write a brief summary of what an EventQueue object does and is
 *	used for.
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include "Event.h"

class EventQueue
{
private:
	int front_ptr;
	int back_ptr;
	int max_events;
	Event *events;

public:
	EventQueue( int max_events );
	~EventQueue(void);

	// Change the queue length
	void queue_length( int max_events );
	void add( Event *new_event );
	Event *get();
};

#endif /* EVENTQUEUE_H_ */
