/**
 * This is a two dimensional SLL, that has been modified
 * to store:
 *      PrimeNode  -  int hash;
 *      Node       -  char *string;
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
    
    int search(int hash) {
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (hash == this->hash)
                return 1;
        return 0;
    }
    
    const PrimeNode *getNode(int hash) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (hash == this->hash)
                return current;

        return NULL;
    }
   
    // Mutators 
    void add(int hash, char *string) {
        if (isEmpty()) {
            first = queue;
            last = queue;
            first = new PrimeNode(hash, string);
        } else {
            last->next = new PrimeNode(hash, string);
            last = last->next;         
        }
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
struct Node {
   char *string;
   Node *next;

    // optional constructor and destructor
    node(char *copy, SubNode *next) {
        this.next = next;  
        this.string = emalloc(strlen(copy));
        strcpy(string, copy);
    }
    ~node() { free(data); }
};

// The inner HashQueue
class SLL {
private:
    Node *first;
    Node *last;

public:
    // Constructor and Destructors
    SLL() {
        first = NULL;
        last = NULL;
    }

    ~SLL() {
        SubNode *current = first;
        while(current != NULL) {
            SubNode *next = current.next;
            delete current;
            current = next;
        }
    }

    // Accessors
    int isEmpty() { return first == NULL; }

    int (*search) (char *) = &getHash;  // Alias to getHash
    
    int getHash(char *string) {
        for (SubNode *current = first; current != NULL; current = current.next)
            if (strcmp(string, current->string))
                return current.hash;
        return 0;
    }
    
    const SubNode *getNode(int hash) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode *current = first; current != NULL; current = current.next)
            if (hash == this->hash)
                return current;

        return NULL;
    }

    // Mutators
    int add(char *string) {
        if(search(string))
            return 0;
        if (isEmpty()) {
            first = queue;
            last = queue;
            first = new Node(string);
        } else {
            last->next = new Node(string);
            last = last->next;         
        }
        return 1;
    }


    void del(Node *del) {
        Node *prev;
        for (Node *current = first; current != NULL; current = current.next)
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

