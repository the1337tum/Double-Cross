#ifndef CyclicArray_H_
#define CyclicArray_H_

#include <new>

/**
 * A wrapping fixed length cyclic array of pointers
 * Intentionally kept as simple as possible
 * Use pointer arithmetic at your own risk!
**/
template <typename ItemType, int size>
class CyclicArray {
private:
    ItemType array[size];
    int offset;

public:
    const int length;
    
    CyclicArray() : length(size) { offset = 0; }
    ~CyclicArray();
    
    // Array subscript operator - pointers are mutable.
    ItemType &operator[](const int index) {
        return array[(index + offset) % length];
    }

    // Cycle the array index up and down.
    void cycleArray(int step) {
        offset = (offset + step) % length;
    }
};

#endif /* CyclicArray_H_*/

