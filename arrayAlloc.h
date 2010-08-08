#ifndef ARRAY_ALLOC_H_
#define ARRAY_ALLOC_H_

// creates a contiguious char array. Must templatise this at some point...
char **char_array_alloc(int rows, int cols);
// Testing for how pointers are incrimented
void testPointers(char **charMap, int rows);

#endif /* ARRAY_ALLOC_H_ */

