/**
 * This hashes strings to binary search trees for parsing
 * options, save files and datastructures. 
 * Use in switch statement, with comparision to the stored string. 
**/
#include "BST.h"
#include "hashFunction.h"
#include "../Art/fileNames.h"

class String~HashTree {
private:
    BinarySearchTree tree
    
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
    int search(char *);

    // Mutators
    addString(char *);
    delString(char *);
};
