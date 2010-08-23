#include "String~HashTree.h"    
#include <string.h>

// Accessors - Returns the ID if found
int HashSLL::search(char *string) {
    int hash = stringHash(string);
    PrimeNode hashNode = primeQueue.search(hash);
    if (hashNode != NULL) {
        
    }
    
    PrimeNode hashNode;
        SubNode stringNode;
        for (stringNode = hashNode.subQueue.first; stringNode != NULL; stringNode = stringNode.next)
            if (strcmp(string, stringNode.string))
               return hashNode.hash;
    }
    return 0;
}

// Will return NULL on not found and ambiguity
char *HashSLL::search(int hash) {
    PrimeNode hashNode;
    for (hashNode = primeQueue.first; hashNode != NULL; hashNode = hashNode.next)
        if (hashNode.hash == hash) {
            
            SubNode stringNode = hashNode.subQueue.first;;
            if (stringNode = hashNode.subQueue.first; stringNode != NULL; stringNode = stringNode.next)
                if (strcmp(string, stringNode.string))
                    return stringNode.String;
        }
    return 0;
}

// Mutators returns the ID on successful insert
int HashSLL::addString(char *newHash) {
    
}
void HashSLL::delString(char *newHash) {

}
