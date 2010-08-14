#include "allocArray.h"
#include <stdio.h>

char **char_array_alloc( int rows, int cols ) {

    char **row_ptr;  // row pointer
    char *array_ptr; // contiguious array pointer
    int index;

    array_ptr = (char*) malloc( rows * cols * sizeof(*array_ptr) );
    if (array_ptr == NULL) {
        printf("\nFailure to allocate room for the array");
	exit(0);
    }

    row_ptr = (char**) malloc( rows * sizeof(*row_ptr) );
    if (row_ptr == NULL) {
        printf("\nFailure to allocate room for pointers");
        exit(0);
    }

    /* Point the pointers */
    for (index = 0; index < rows; index++) {
        row_ptr[index] = array_ptr + (index * cols);
    }
    return row_ptr;
}

void testPointers( char **charMap, int rows ) {
    
    printf("\n\nTesting for how pointers are incrimented:");
    printf("\n\nIndex   Pointer(hex)  Diff.(dec)");

    for (int row = 0; row < rows; row++) {
        printf("\n%d         %p", row, charMap[row]);
        if (row > 0)
            printf("              %d", (charMap[row] - charMap[row-1]));
    }
}

