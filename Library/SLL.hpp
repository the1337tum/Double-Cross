/**
 * This is a two dimensional SLL, that has been modified
 * to store:
 *      PrimeNode  -  int ID;
 *      Node       -  ItemType *data;
**/
#include <new>
#include <string.h>
#include "alloc.h" 

// The node for the SSL
template <typename ItemType>
struct Node {
    int ID;
    ItemType *data;
    Node *next;

    Node(ItemType *data) {
        this->data = data;
    }
    Node(int ID, ItemType *data) {
        this->ID = ID;
        this->data = data;
    }
    ~Node() { free(data); }
};

template <typename ItemType>
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

    SLL(ItemType *data) {
        first = new Node<ItemType>(data);
        last = NULL;
    }

    SLL(int ID, ItemType *data) {
        first = new Node<ItemType>(ID, data);
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

    int getID(ItemType *data) {
        if (isEmpty())
            return 0;
        
        for (Node *current = first; current != NULL; current = current->next)
            if (current == data)
                return current->ID;
        return 0;
    }
    
    int search(int ID) {
        if (isEmpty())
            return 0;
        
        for (Node *current = first; current != NULL; current = current->next)
            if (current->getID() == ID)
                return 1;
        return 0;
    }

    const Node *getNode(ItemType *data) {
        if (isEmpty())
            return NULL;
            
        for (Node *current = first; current != NULL; current = current->next)
            if (current == data)
                return current;
        
        return NULL;
    }

    const Node *getNode(int ID) {
        if (isEmpty())
            return NULL;
            
        for (Node *current = first; current != NULL; current = current->next)
            if (ID == current->ID)
                return current;

        return NULL;
    }

    // Mutators
    int add(int ID, ItemType *data) {
        if(getID(data))
            return 0; // No duplicates
        if (isEmpty()) {
            first = new Node(ID, data);
        } else {
            last->next = new Node(ID, data);
            last = last->next;
        }
        return 1;
    }

    int add(ItemType *data) {
        if(getID(data)) 
            return 0; // No duplicates
        if (isEmpty()) {
            first = new Node(data);
        } else {
            last->next = new Node(data);
            last = last->next;
        }
        return 1;
    }


    void del(Node *del) {
        Node *prev;
        if (isEmpty())
            return;
        do {
            Node *current = first
            if (current == del)
                if (prev == NULL) {                 // First Node 
                    first = current->next;
                    delete current;
                    return; 
                } else if (current->next == NULL) { // Last Node
                    prev->next = NULL;
                    last = prev;
                    delete current; 
                    return;
                } else {                            // The middle of the list
                    prev->next = current->next;
                    delete current;
                    return;
                }
            prev = current;
            current = current->next; 
        } while (current != NULL);
    }
};


// A node for a two dimensional SLL
template <typename ItemType>
struct PrimeNode {
    int ID;
    SLL<ItemType> subSLL;
    PrimeNode *next;

    // optional constructor and destructor
    PrimeNode(int key, char *string) : ID(key) { this->subSLL = new SLL(key, string); }
    ~PrimeNode() { delete subSLL; }
};

// The outer SLL
template <typename ItemType>
class PrimeSLL {
private:
    PrimeNode *first;
    PrimeNode *last;

public:
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
    
    int search(int ID) {
        for (PrimeNode *current = first; current != NULL; current = current->next)
            if (ID == current->ID)
                return 1;
        return 0;
    }
    
    const PrimeNode *getNode(int ID) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode *current = first; current != NULL; current = current->next)
            if (ID == current->ID)
                return current;

        return NULL;
    }
   
    // Mutators 
    void add(int ID, ItemType *data) {
        if (isEmpty()) {
            first = new PrimeNode<ItemType>(ID, data);
        } else {
            PrimeNode *node = getNode(ID);
            if (node == NULL) {
                last->next = new PrimeNode<ItemType>(ID, string);
                last = last->next;
            } else {
                node->subSLL->add(ID, data);
            }
        }
    }

    void del(PrimeNode *del) {
        PrimeNode *prev;
        if (isEmpty())
            return;
        do {
            PrimeNode *current = first
            if (current == del)
                if (prev == NULL) {                 // First Node 
                    first = current->next;
                    delete current;
                    return; 
                } else if (current->next == NULL) { // Last Node
                    prev->next = NULL;
                    last = prev;
                    delete current; 
                    return;
                } else {                            // The middle of the list
                    prev->next = current->next;
                    delete current;
                    return;
                }
            prev = current;
            current = current->next; 
        } while (current != NULL);
    }
};
