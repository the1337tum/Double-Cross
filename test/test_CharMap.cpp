/**	Test the CharMap object
 *
 *	Tests:
 *	1)  Construct a CharMap object with parameters.
 *		FAIL
 *	2)  Construct a CharMap object from another CharMap object.
 *		FAIL
 *	3)  Destruct a CharMap object.
 *		FAIL
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../CharMap.cpp"

using namespace std;

int main(int argc, char *argv[]) {

	/**	Test 1
	 *	Construct a CharMap object with three parameters.
	 */

	char c1;
	char * c2;
	char ** c3;
	c1 = 'x';
	c2 = &c1;
	c3 = &c2;
	CharMap * m1 = new CharMap(1, 1, c3);

	/**	Test 2
	 *	Construct a CharMap object from another CharMap object.
	 */

	CharMap * m2 = new CharMap(*m1);

	/**	Test 3
	 *	Destruct a CharMap object.
	 */

	delete m1;
	delete m2;
}
