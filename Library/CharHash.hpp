/**
 * This hashes strings to binary search trees for parsing
 * options, save files and datastructures.
 * - Extremely fast at hashing new input values, at minimal 
 *   cost to space complexity.
 * - Worst case is linear in the scope of the global hash.
 * - Use in switch statement, with comparision to the stored string. 
**/
#include <string.h>
#include "hashFunction.h"
#include "alloc.h"
#include "../Art/fileNames.h"
#include "../IO/data_structures/Queue.hpp"

class String~HashQueue {
private:
    PrimeQueue primeQueue;

public:
    // Constructors and destructors
    String~HashTree() { 
        tree = new BinarySearchTree(); 
    }
    ~String~HashTree {
        delete tree;
    }

    /* Uses both pointer and string comparison *
     * Returns the hashed value of the string  */
    int search(char *candidate);

    // Mutators
    void addString(char *newHash);
    void delString(char *newHash);
};

