#include "Keyboard.h"
#include "CharMap.h"
#include "Event.h"
#include <windows.h>

//extern const Rect dimensions {} 

void test_keyboard(Keyboard *keyboard);

int main()
{
	// intro();
	Keyboard *keyboard = new Keyboard();
	// int selection = menu( keyboard );
	test_keyboard( keyboard );
	/*
	while(1)
	{
		switch( selection ) {
		case 0:
			// new_game();
			break;
		case 1:
			// load_game();
			break;
		case 3:
			// settings();
			break;
		case 4:
			exit(EXIT_SUCCESS);
		default:
			exit(EXIT_FAILURE);
		}
	}*/

}

#define NUM_MENU 4
int menu( Keyboard *keyboard ) {	
	int selection = 0;
	//CharMap menu_map = new CharMap( dimensions->start_x, dimensions->start_y, dimensions->end_x, dimensions->end_y, &menus[selection] );
	
	Queue<int, MAX_KEYS> *keyEvents = keyboard->readEvents();
	while(1) {
		while(! keyEvents->isEmpty() ) {
			KeyPressed key = (KeyPressed) keyEvents->get();
			switch( key ) {
			case keyReturn:
				return selection;

			case keyUp:
				if( selection == 0 ) { break; }
				selection--;
				//menu_map.map = &menus[selection];
				break;

			case keyDown:
				if( selection == NUM_MENU ) { break; }
				selection++;
				//menu_map.map = &menus[selection];
				break;
			}
		}
	}
	return 0;
}

void new_game(Keyboard *keyboard)
{
	//GameMap *level = new GameMap( dimensions->end_x, dimensions->end_y, &levels[0] );
	//Queue<Event, 10> event_queue;

	// Poll for event
	while(1)
	{
		// Human stuff
		int playerState = 0; // To simulate walking
		Queue<int, MAX_KEYS> *keyEvents = keyboard->readEvents();
		while(! keyEvents->isEmpty() )
		{
			KeyPressed key = (KeyPressed) keyEvents->get();
			switch( key ) {
			case keyReturn:
				break;

			case keyLeft:
				if( playerState ) { 
					playerState = 0; 
				} else {
					playerState = 1;
				}
				// event_queue.put(new EventMove( -1, 0, PLAYER, us, &player[playerState] ) );
				break;

			case keyUp:
				if( playerState ) { 
					playerState = 0; 
				} else {
					playerState = 1;
				}
				// event_queue.put(new EventMove( 0, -1, PLAYER, us, &player[playerState] ) );
				break;

			case keyRight:
				if( playerState ) { 
					playerState = 0; 
				} else {
					playerState = 1;
				}
				// event_queue.put(new EventMove( 1, 0, PLAYER, us, &player[playerState] ) );
				break;

			case keyDown:
				if( playerState ) { 
					playerState = 0; 
				} else {
					playerState = 1;
				}
				// event_queue.put(new EventMove( 0, 1, PLAYER, us, &player[playerState] ) );
				break;
			}
		}

		// Timer triggered Events
		//ai_events( event_queue );
	}
}

void test_keyboard(Keyboard *keyboard)
{
	while(1)
	{
		Queue<int, MAX_KEYS> *keyEvents = keyboard->readEvents();
		while(! keyEvents->isEmpty() ){
			KeyPressed key = (KeyPressed) keyEvents->get();
			switch( key ) {
			case keyReturn:
				printf("You wish..\n");
				break;

			case keySpace:
				printf("BANG!\n");
				break;
			case keyLeft:
				printf("You are moving to the left! \n");
				break;

			case keyUp:
				printf("You are moving up! \n");
				break;

			case keyRight:
				printf("You are moving to the right! \n");
				break;

			case keyDown:
				printf("You are moving down! \n");
				break;
			}
		}
	}
}
