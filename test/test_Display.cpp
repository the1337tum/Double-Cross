/*	Test the CharMap object * *	Tests:
 *	1)  Construct a Display object with parameters.
 *		FAIL
 *	2)  Destruct a CharMap object.
 *		FAIL
 */

#include <stdio.h>
#include <stdlib.h>
#include "../IO/Display.hpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a CharMap object with three parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int charmap1_x = 0;
	int charmap1_y = 0;
	int charmap1_cols = 1;
	int charmap1_rows = 1;

	CharMap * charmap1 = new CharMap(charmap1_x, charmap1_y, charmap1_cols,
		charmap1_rows, &char3);

	/**	Test 2
	 *	Deep copy a CharMap object from another CharMap object.
	 */

	CharMap * charmap2 = new CharMap(*charmap1);

	/**	Test
	 *	Assignment by copy assignment operator
	 */

	CharMap * charmap1_copy = charmap1;

	/**	Test 5
	 *	Read state from a CharMap object.
	 */

	Rect * location = (*charmap1).getLocation();
	printf("%d\n", (*location).start_x);
	printf("%d\n", (*location).start_y);
	printf("%d\n", (*location).cols);
	printf("%d\n", (*location).rows);

	char *** charmap1_map = (*charmap1).getMap();

	printf("\nTesting constructors:\n");
	printf("&charmap1: %p\n", &charmap1);
	printf("&charmap1_copy: %p\n", &charmap1_copy);
	printf("&charmap2: %p\n", &charmap2);
	printf("&(*charmap1): %p\n", charmap1);
	printf("&(*charmap1_copy): %p\n", charmap1_copy);
	printf("&(*charmap2): %p\n\n", charmap2);

	delete charmap2;
	delete charmap1;

	return 0;
}

