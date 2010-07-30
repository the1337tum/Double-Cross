#pragma once
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