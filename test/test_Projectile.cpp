/*	Test the Projectile object
 *
 *	Tests:
 *	1)  Construct a Projectile object with parameters.
 *		PASS
 *	2)  Destruct a Projectile object.
 *		PASS
 *	3)  Shallow copy a Projectile object.
 *		PASS
 *	4)  Deep copy a Projectile object.
 *		UNTESTED
 *	5)  Move a Projectile object in each direction.
 *		UNTESTED
 *	6)  Replace a Projectile object's CharMap
 *		UNTESTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/Projectile.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a Projectile object with parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int projectile1_x = 0;
	int projectile1_y = 0;
	int projectile1_cols = 1;
	int projectile1_rows = 1;

	Projectile * projectile1 = new Projectile(projectile1_x, projectile1_y,
		projectile1_cols, projectile1_rows, &char3);

	/**	Test 3
	 *	Shallow copy a Projectile object.
	 */

	Projectile * projectile1_copy = projectile1;

	printf("\nTesting shallow copy:\n");
	printf("&projectile1: %p\n", &projectile1);
	printf("&projectile1_copy: %p\n", &projectile1_copy);
	printf("&(*projectile1): %p\n", projectile1);
	printf("&(*projectile1_copy): %p\n\n", projectile1_copy);

	/**	Test 2
	 *	Destruct a Projectile object.
	 */

	delete projectile1;

	return 0;
}
