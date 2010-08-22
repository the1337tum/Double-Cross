/*	Test the Avatar object
 *
 *	Tests:
 *	1)  Construct a Avatar object with parameters.
 *		PASS
 *	2)  Destruct a Avatar object.
 *		PASS
 *	3)  Shallow copy a Avatar object.
 *		PASS
 *	4)  Deep copy a Avatar object.
 *		UNTESTED
 *	5)  Move a Avatar object in each direction.
 *		UNTESTED
 *	6)  Replace a Avatar object's CharMap
 *		UNTESTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/Avatar.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a Avatar object with parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int avatar1_x = 0;
	int avatar1_y = 0;
	int avatar1_cols = 1;
	int avatar1_rows = 1;

	Avatar * avatar1 = new Avatar(avatar1_x, avatar1_y, avatar1_cols,
		avatar1_rows, &char3);

	/**	Test 3
	 *	Shallow copy a Avatar object.
	 */

	Avatar * avatar1_copy = avatar1;

	printf("\nTesting shallow copy:\n");
	printf("&avatar1: %p\n", &avatar1);
	printf("&avatar1_copy: %p\n", &avatar1_copy);
	printf("&(*avatar1): %p\n", avatar1);
	printf("&(*avatar1_copy): %p\n\n", avatar1_copy);

	/**	Test 2
	 *	Destruct a Avatar object.
	 */

	delete avatar1;

	return 0;
}
