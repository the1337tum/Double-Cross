/**
 * This is a two dimensional queue, that has been modified
 * to store:
 *      PrimeNode  -  int hash;
 *      SubNode    -  char *string;
**/
#include <new.h>
#include <string.h>

// A Queue node for storing Queues
struct PrimeNode {
    int hash;
    SubQueue subQueue;
    SubQueue *next;

    // optional constructor and destructor
    node(int key char string) : hash(key) { subQueue = new SubQueue(string); }
    ~node() { delete subQueue; }
};

// The outer queue - to store the hashes and subqueues
class PrimeSLL {
private:
    PrimeNode *first;
    PrimeNode *last;

public:
    const int length;

    PrimeSLL() {
        first = NULL;
        last = NULL;
    }

    ~PrimeQueue() {
        PrimeNode *current = first;
        while(current != NULL) {
            PrimeNode *next = current.next;
            delete current;
        }
    }
     
    // Accessors     
    int isEmpty() { return first == NULL; }
    
    const PrimeNode *search(int hash) {
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (hash == this->hash)
                return 1;
        return 0;
    }
   
    // Mutators 
    void put(int hash, char *string) {
        if (isEmpty()) {
            first = queue;
            last = queue;
            first = new PrimeNode(hash, string);
        } else {
            last->next = new PrimeNode(hash, string);
            last = last->next;         
        }
    }
    
    const PrimeNode *get(int hash) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (hash == this->hash)
                return current;

        return NULL;
    }

    void del(PrimeNode *del) {
        PrimeNode *prev;
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (current == del)
                if (first == last){                 // Only one node
                    first = last = NULL;
                    delete current;
                    return;
                } else if (prev == NULL) {          // First Node 
                    first = current.next;
                    delete current;
                    return; 
                } else if (current.next == NULL) {  // Last Node
                    prev.next = NULL;
                    last = prev;
                    delete current; 
                    return;
                } else {                            // The middle of the list
                    prev.next = current.next;
                    delete current;
                    return;
                }
    }
};

// The queue node to store the string to the hash.
struct SubNode {
   char *string;
   SubNode *next;

    // optional constructor and destructor
    node(char *copy, SubNode *next) {
        this.next = next;  
        this.string = emalloc(strlen(copy));
        strcpy(string, copy);
    }
    ~node() { free(data); }
};

// The inner HashQueue
class SubSLL {
private:
    SubNode *first;
    SubNode *last;

public:
    // Constructor and Destructors
    SubSLL() {
        first = NULL;
        last = NULL;
    }

    ~SubSLL() {
        SubNode *current = first;
        while(current != NULL) {
            SubNode *next = current.next;
            delete current;
            current = next;
        }
    }

    // Accessors
    int isEmpty() { return first == NULL; }

    PrimeNode *search(char *string) {
        for (SubNode *current = first; current != NULL; current = current.next)
            if (strcmp(string, current->string))
                return 1;
        return 0;
    }
    
    // Mutators
    int put(char *string) {
        if(search(string))
            return 0;
        if (isEmpty()) {
            first = queue;
            last = queue;
            first = new SubNode(string);
        } else {
            last->next = new SubNode(string);
            last = last->next;         
        }
        return 1;
    }

    const PrimeNode *get(int hash) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (hash == this->hash)
                return current;

        return NULL;
    }

    void del(PrimeNode *del) {
        PrimeNode *prev;
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (current == del)
                if (first == last){                 // Only one node
                    first = last = NULL;
                    delete current;
                    return;
                } else if (prev == NULL) {          // First Node 
                    first = current.next;
                    delete current;
                    return; 
                } else if (current.next == NULL) {  // Last Node
                    prev.next = NULL;
                    last = prev;
                    delete current; 
                    return;
                } else {                            // The middle of the list
                    prev.next = current.next;
                    delete current;
                    return;
                }
    }
};

