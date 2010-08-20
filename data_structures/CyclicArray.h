#ifndef CyclicArray_H_
#define CyclicArray_H_

#include <new>

/**
 *  A wrapping fixed length cyclic array of pointers 
 *  Intentionally kept as simple as possible
 *  Use pointer arithmetic at your own risk!
**/

class CyclicArray { 
private:
    char *array[size_];
    int offset = 0;

public:
    const int length;
    
    CyclicArray(int size);
    ~CyclicArray();
    
    // Array subscript operator - pointers are mutable.
    Type &operator[](const int index);
    // Cycle the array index up and down.
    cycleArray(int step);
};

#endif /* CyclicArray_H_*/
