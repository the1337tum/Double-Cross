/**	EventQueue
 *	More detailed documentation can be found in the header file,
 *	EventQueue.h
 */

#include "StdAfx.h"
#include "EventQueue.h"
#include <windows.h>

EventQueue::EventQueue( int max_events )
{
	events = (events*) malloc( max_events * sizeof((*events)) );
}


EventQueue::~EventQueue(void)
{
	free( events );
}

void EventQueue::queue_length( int max_events )
{
	if( queue_ptr > max_events ){ queue_ptr = max_events; }

	(*this).max_events = max_events;

	Event *new_queue = malloc( max_events * sizeof((*new_queue)) );
	for( int count = 0; count < max_events; count++ )
		new_queue[count] = events[count];
	
	free( events );
	events = new_queue;
}

void EventQueue::add( Event *new_event )
{
	if( queue_ptr > max_events ){ return; }
	events[queue_ptr++] = new Event( new_event );
	
}

Event *EventQueue::get(){
	return &events[queue_ptr--];
}
