#ifndef ARRAY_ALLOC_H_
#define ARRAY_ALLOC_H_

// creates a contiguious char array. Must templatise this at some point...
template <typename Type>
Type **alloc_array_2d(Type type, int rows, int cols) {
    char **row_ptr;  // row pointer
    char *array_ptr; // contiguious array pointer
    int index;

    array_ptr = (type*) malloc( rows * cols * sizeof(*array_ptr) );
    if (array_ptr == NULL) {
        printf("\nFailure to allocate room for the array");
	exit(0);
    }
    
    row_ptr = (type**) malloc( rows * sizeof(*row_ptr) );
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

// Testing for how pointers are incrimented
void test_alloc array(void **array, int rows) {
    printf("\n\nTesting for how pointers are incrimented:");
    printf("\n\nIndex   Pointer(hex)  Diff.(dec)");

    for (int row = 0; row < rows; row++) {
        printf("\n%d         %p", row, array[row]);
        if (row > 0)
            printf("              %p", (array[row] - array[row-1]));
    }
}
#endif /* ARRAY_ALLOC_H_ */

