#include <stdio.h>
#include <stdlib.h>
//#include "input.h"
#include "CharMap.cpp"

using namespace std;

int main(int argc, char *argv[]) {
//    return readFile(*argv);
	char a;
	char * b;
	char ** c;
	a = 'c';
	b = &a;
	c = &b;
	printf("Testing the CharMap class:\n");
	CharMap * map = new CharMap(1, 1, c);
	delete map;
}
