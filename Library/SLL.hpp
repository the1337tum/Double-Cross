/**
 * This is a two dimensional SLL, that has been modified
 * to store:
 *      PrimeNode  -  int hash;
 *      Node       -  char *string;
**/
#include <new>
#include <string.h>
#include "alloc.h" 

// The node for the SSL
struct Node {
    int hash;
    char *string;
    Node *next;

    Node(char *string) {
        this->string = (char*) emalloc(strlen(string));
        strcpy(this->string, string);
    }
    Node(int hash, char *string) {
        this->hash = hash;
        this->string = (char*) emalloc(strlen(string));
        strcpy(this->string, string);
    }
    ~Node() { free(string); }
};

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

    SLL(char *string) {
        first = new Node(string);
        last = NULL;
    }

    ~SLL() {
        Node *current = first;
        while(current != NULL) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // Accessors
    int isEmpty() { return first == NULL; }

    int getHash(char *string) {
        if (isEmpty())
            return 0;
        
        for (Node *current = first; current != NULL; current = current->next)
            if (strcmp(string, current->string))
                return current->hash;
        return 0;
    }
    
    const Node *getNode(char *string) {
        if (isEmpty())
            return NULL;
            
        for (Node *current = first; current != NULL; current = current->next)
            if (strcmp(string, current->string))
                return current;
        
        return NULL;
    }

    const Node *getNode(int hash) {
        if (isEmpty())
            return NULL;
            
        for (Node *current = first; current != NULL; current = current->next)
            if (hash == current->hash)
                return current;

        return NULL;
    }

    // Mutators
    int add(char *string) {
        if(getHash(string))
            return 0;
        if (isEmpty()) {
            first = new Node(string);
        } else {
            last->next = new Node(string);
            last = last->next;         
        }
        return 1;
    }


    void del(Node *del) {
        Node *prev;
        for (Node *current = first; current != NULL; current = current->next)
            if (current == del)
                if (first == last){                 // Only one node
                    first = last = NULL;
                    delete current;
                    return;
                } else if (prev == NULL) {          // First Node 
                    first = current->next;
                    delete current;
                    return; 
                } else if (current->next == NULL) {  // Last Node
                    prev->next = NULL;
                    last = prev;
                    delete current; 
                    return;
                } else {                            // The middle of the list
                    prev->next = current->next;
                    delete current;
                    return;
                }
    }
};


// A node for a two dimensional SLL
struct PrimeNode {
    int hash;
    SLL subSLL;
    PrimeNode *next;

    // optional constructor and destructor
    PrimeNode(int key, char *string) : hash(key) { this->subSLL = new SLL(key, string); }
    ~PrimeNode() { delete subSSL; }
};

// The outer SLL
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

    ~PrimeSLL() {
        PrimeNode *current = first;
        while(current != NULL) {
            PrimeNode *next = current->next;
            delete current;
        }
    }
     
    // Accessors     
    int isEmpty() { return first == NULL; }
    
    int search(int hash) {
        for (PrimeNode *current = first; current != NULL; current = current->next)
            if (hash == this->hash)
                return 1;
        return 0;
    }
    
    const PrimeNode *getNode(int hash) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode *current = first; current != NULL; current = current->next)
            if (hash == current->hash)
                return current;

        return NULL;
    }
   
    // Mutators 
    void add(int hash, char *string) {
        if (isEmpty()) {
            first = new PrimeNode(hash, string);
        } else {
            last->next = new PrimeNode(hash, string);
            last = last->next;
        }
    }

    void del(PrimeNode *del) {
        PrimeNode *prev;
        for (PrimeNode *current = first; current != NULL; current = current->next)
            if (current == del)
                if (first == last){                 // Only one node
                    first = last = NULL;
                    delete current;
                    return;
                } else if (prev == NULL) {          // First Node 
                    first = current->next;
                    delete current;
                    return; 
                } else if (current->next == NULL) {  // Last Node
                    prev.next = NULL;
                    last = prev;
                    delete current; 
                    return;
                } else {                            // The middle of the list
                    prev.next = current->next;
                    delete current;
                    return;
                }
    }
};
