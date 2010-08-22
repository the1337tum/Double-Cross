/**
 * This hashes strings to binary search trees for parsing
 * options, save files and datastructures. 
 * Use in switch statement, with comparision to the stored string. 
 *
 ** The class interface for comparisions
 ** 1 for found match, 0 for failure. 
 * int matchString(char *) 
 *
 **/
#include "BST.h"
#include "hashFunction.h"


extern static struct FileNames{
    char *config = "Config.txt";
    /**
     * Can you give me some more examples, 
     * alturnatively, just add the names of all 
     * like the example above.
    **/
}FILE_NAMES;

/**
 * Just treat this like any other datastructure
 *
**/
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

    // Accessors
    /* Uses both pointer and string comparison. *
     * Returns the hashed value of the string.  */
    int search(char *);

    // Mutators
    addString(char *);
    delString(char *);
};
