/*	Test the Person object
 *
 *	Tests:
 *	1)  Construct a Person object with parameters.
 *		PASS
 *	2)  Destruct a Person object.
 *		PASS
 *	3)  Shallow copy a Person object.
 *		PASS
 *	4)  Deep copy a Person object.
 *		UNTESTED
 *	5)  Move a Person object in each direction.
 *		UNTESTED
 *	6)  Replace a Person object's CharMap
 *		UNTESTED
 */

#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/Person.cpp"

using namespace std;

int main() {

	/**	Test 1
	 *	Construct a Person object with parameters.
	 */

	char char1;
	char * char2;
	char ** char3;
	char1 = 'x';
	char2 = &char1;
	char3 = &char2;

	int person1_x = 0;
	int person1_y = 0;
	int person1_cols = 1;
	int person1_rows = 1;

	Person * person1 = new Person(person1_x, person1_y, person1_cols,
		person1_rows, &char3);

	/**	Test 3
	 *	Shallow copy a Person object.
	 */

	Person * person1_copy = person1;

	printf("\nTesting shallow copy:\n");
	printf("&person1: %p\n", &person1);
	printf("&person1_copy: %p\n", &person1_copy);
	printf("&(*person1): %p\n", person1);
	printf("&(*person1_copy): %p\n\n", person1_copy);

	/**	Test 2
	 *	Destruct a Person object.
	 */

	delete person1;

	return 0;
}
