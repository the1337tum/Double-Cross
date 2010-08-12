/**	Test the CharMap object
 *
 *	Passed Tests:
 *	1)  Construct a CharMap object.
 *	2)  Destruct a CharMap object.
 *
 *	Failed Tests:
 *
 *	Untested Tests:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "CharMap.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	char a;
	char * b;
	char ** c;
	a = 'x';
	b = &a;
	c = &b;
	CharMap * map = new CharMap(1, 1, c);
	CharMap * m2 = new CharMap(*map); 
	delete map;
	delete m2;
}
