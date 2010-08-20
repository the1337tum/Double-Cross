#include "CyclicArray.h";

using namespace CyclicArray;


CyclicArray(int size) : size_(size), length(size) {} 

~CyclicArray() { /* All memory on the stack */ };
    
// Array subscript operator - pointers are mutable
Type &operator[](const int index) {
    return array[(index + offset) % length];
}
    
cycleArray(int step) {
    offset = (offset + step) % length;
}

