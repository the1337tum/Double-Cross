/*	Test the Movable object
 *
 *	Tests:
 *	1)  Construct a Movable object with parameters.
 *		PASS
 *	2)  Destruct a Movable object.
 *		PASS
 *	3)  Shallow copy a Movable object.
 *		PASS
 *	4)  Deep copy a Movable object.
 *		UNTESTED
 *	5)  Move a Movable object in each direction.
 *		UNTESTED
 *	6)  Replace a Movable object's CharMap
 *		UNTESTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "../AI/data_structures/Movable.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a Movable object with parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int movable1_x = 0;
	int movable1_y = 0;
	int movable1_cols = 1;
	int movable1_rows = 1;

	Movable * movable1 = new Movable(movable1_x, movable1_y, movable1_cols,
		movable1_rows, &char3);

	/**	Test 3
	 *	Shallow copy a Movable object.
	 */

	Movable * movable1_copy = movable1;

	printf("\nTesting shallow copy:\n");
	printf("&movable1: %p\n", &movable1);
	printf("&movable1_copy: %p\n", &movable1_copy);
	printf("&(*movable1): %p\n", movable1);
	printf("&(*movable1_copy): %p\n\n", movable1_copy);

	/**	Test 2
	 *	Destruct a Movable object.
	 */

	delete movable1;

	return 0;
}
