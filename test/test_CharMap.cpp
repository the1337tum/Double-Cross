/*	Test the CharMap object
 *
 *	Tests:
 *	1)  Construct a CharMap object with parameters.
 *		PASS
 *	2)  Deep copy a CharMap object from another CharMap object. 
 *		FAIL
 *	3)  Destruct a CharMap object.
 *		PASS
 *	4)  Shallow copy a CharMap object from another CharMap object.
 *		UNTESTED
 *	5)  Read state from a CharMap object.
 *		PASS
 */

#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/CharMap.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a CharMap object with three parameters.
	 */

	char c1;
	char * c2;
	char ** c3;
	c1 = 'x';
	c2 = &c1;
	c3 = &c2;

	int m1_x = 0;
	int m1_y = 0;
	int m1_cols = 1;
	int m1_rows = 1;

	CharMap * m1 = new CharMap(m1_x, m1_y, m1_cols, m1_rows, &c3);

	/**	Test 2
	 *	Deep copy a CharMap object from another CharMap object.
	 */

	CharMap * m2 = new CharMap(*m1);

	/**	Test 3
	 *	Destruct a CharMap object.
	 */

	delete m2;

	/**	Test 4
	 *	Shallow copy a CharMap object from another CharMap object.
	 */

	//CharMap * m1_copy = m1;

	/**	Test 5
	 *	Read state from a CharMap object.
	 */

	Rect * location = (*m1).getLocation();
	printf("%d\n", (*location).start_x);
	printf("%d\n", (*location).start_y);
	printf("%d\n", (*location).cols);
	printf("%d\n", (*location).rows);

	char *** map = (*m1).getMap();

	delete m1;

	return 0;
}
