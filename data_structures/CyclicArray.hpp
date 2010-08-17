#ifndef CyclicArray_H_
#define CyclicArray_H_

#include <stdio>
#include <new>

/**
 *  A wrapping fixed length cyclic array of pointers 
 *  Intentionally kept as simple as possible
 *  Use pointer arithmetic at your own risk!
**/

using namespace std;

template <typename Type, int size>
class CyclicArray { 
private:
    Type *array[size];
    int offset = 0;

public:
    const int length = size;
    
    CyclicArray() { /* All taken care of by the template */ } 
    ~CyclicArray() { /* All memory on the stack */ };
    
    // Array subscript operator - pointers are mutable
    Type &operator[](const int index) {
        return array[(index + offset) % length];
    }
    
    cycleArray(int step) {
        offset = (offset + step) % length;
    }
};

#endif /* CyclicArray_H_*/
