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

class String~HashTree {
private:
    BinarySearchTree tree;
    
public:
    String~HashTree {

    }


    // Mutators
    addString(char *);
    delString(char *);

    

};