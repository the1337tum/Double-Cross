/*	Test the Enemy object
 *
 *	Tests:
 *	1)  Construct a Enemy object with parameters.
 *		PASS
 *	2)  Destruct a Enemy object.
 *		PASS
 *	3)  Shallow copy a Enemy object.
 *		PASS
 *	4)  Deep copy a Enemy object.
 *		UNTESTED
 *	5)  Move a Enemy object in each direction.
 *		UNTESTED
 *	6)  Replace a Enemy object's CharMap
 *		UNTESTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "../AI/data_structures/Enemy.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a Enemy object with parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int enemy1_x = 0;
	int enemy1_y = 0;
	int enemy1_cols = 1;
	int enemy1_rows = 1;

	Enemy * enemy1 = new Enemy(enemy1_x, enemy1_y, enemy1_cols,
		enemy1_rows, &char3);

	/**	Test 3
	 *	Shallow copy a Enemy object.
	 */

	Enemy * enemy1_copy = enemy1;

	printf("\nTesting shallow copy:\n");
	printf("&enemy1: %p\n", &enemy1);
	printf("&enemy1_copy: %p\n", &enemy1_copy);
	printf("&(*enemy1): %p\n", enemy1);
	printf("&(*enemy1_copy): %p\n\n", enemy1_copy);

	/**	Test 2
	 *	Destruct a Enemy object.
	 */

	delete enemy1;

	return 0;
}
