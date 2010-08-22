/*	Test the Collidable object
 *
 *	Tests:
 *	1)  Construct a Collidable object with parameters.
 *		PASS
 *	2)  Destruct a Collidable object.
 *		PASS
 *	3)  Shallow copy a Collidable object.
 *		PASS
 *	4)  Deep copy a Collidable object.
 *		UNTESTED
 *	5)  Replace a Collidable object's CharMap
 *		UNTESTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/Collidable.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a Collidable object with parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int collidable1_x = 0;
	int collidable1_y = 0;
	int collidable1_cols = 1;
	int collidable1_rows = 1;

	Collidable * collidable1 = new Collidable(collidable1_x,
		collidable1_y, collidable1_cols, collidable1_rows, &char3);

	/**	Test 3
	 *	Shallow copy a Collidable object.
	 */

	Collidable * collidable1_copy = collidable1;

	printf("\nTesting shallow copy:\n");
	printf("&collidable1: %p\n", &collidable1);
	printf("&collidable1_copy: %p\n", &collidable1_copy);
	printf("&(*collidable1): %p\n", collidable1);
	printf("&(*collidable1_copy): %p\n\n", collidable1_copy);

	/**	Test 2
	 *	Destruct a Collidable object.
	 */

	delete collidable1;

	return 0;
}
