/**
 * This is a two dimensional SLL, that has been modified
 * to store:
 *      PrimeNode  -  int ID;
 *      Node       -  ItemType *data; (pointers)
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
    Node<ItemType> *first;
    Node<ItemType> *last;

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
        Node<ItemType> *current = first;
        while(current != NULL) {
            Node<ItemType> *next = current->next;
            delete current;
            current = next;
        }
    }

    // Accessors
    int isEmpty() { return first == NULL; }
    const Node<ItemType> *getFirst() { return first; }
    const Node<ItemType> *getLast() { return last; }

    int search(int ID) {
        if (isEmpty())
            return 0;
        
        for (Node<ItemType> *current = first; current != NULL; current = current->next)
            if (current->getID() == ID)
                return 1;
        return 0;
    }

    int getID(ItemType *data) {
        if (isEmpty())
            return 0;
        
        for (Node<ItemType> *current = first; current != NULL; current = current->next)
            if (current == data)
                return current->ID;
        return 0;
    }
    
    const Node<ItemType> *getNode(ItemType *data) {
        if (isEmpty())
            return NULL;
            
        for (Node<ItemType> *current = first; current != NULL; current = current->next)
            if (current == data)
                return current;
        
        return NULL;
    }

    const Node<ItemType> *getNode(int ID) {
        if (isEmpty())
            return NULL;
            
        for (Node<ItemType> *current = first; current != NULL; current = current->next)
            if (ID == current->ID)
                return current;

        return NULL;
    }

    // Mutators
    int add(int ID, ItemType *data) {
        if(getID(data))
            return 0; // No duplicates
        if (isEmpty()) {
            first = new Node<ItemType>(ID, data);
        } else {
            last->next = new Node<ItemType>(ID, data);
            last = last->next;
        }
        return 1;
    }

    int add(ItemType *data) {
        if(getID(data)) 
            return 0; // No duplicates
        if (isEmpty()) {
            first = new Node<ItemType>(data);
        } else {
            last->next = new Node<ItemType>(data);
            last = last->next;
        }
        return 1;
    }


    void del(Node<ItemType> *del) {
        Node<ItemType> *prev;
        if (isEmpty())
            return;
        Node<ItemType> *current = first;
        do {
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
    PrimeNode(int key, char *string) : ID(key) { this->subSLL = new SLL<ItemType>(key, string); }
    ~PrimeNode() { delete subSLL; }
};

// The outer SLL
template <typename ItemType>
class PrimeSLL {
private:
    PrimeNode<ItemType> *first;
    PrimeNode<ItemType> *last;

public:
    PrimeSLL() {
        first = NULL;
        last = NULL;
    }

    ~PrimeSLL() {
        PrimeNode<ItemType> *current = first;
        while(current != NULL) {
            PrimeNode<ItemType> *next = current->next;
            delete current;
        }
    }
     
    // Accessors     
    int isEmpty() { return first == NULL; }
    
    int search(int ID) {
        for (PrimeNode<ItemType> *current = first; current != NULL; current = current->next)
            if (ID == current->ID)
                return 1;
        return 0;
    }
    
    const PrimeNode<ItemType> *getNode(int ID) {
        if (isEmpty())
            return NULL;
            
        for (PrimeNode<ItemType> *current = first; current != NULL; current = current->next)
            if (ID == current->ID)
                return current;

        return NULL;
    }
   
    // Mutators 
    void add(int ID, ItemType *data) {
        if (isEmpty()) {
            first = new PrimeNode<ItemType>(ID, data);
        } else {
            PrimeNode<ItemType> *node = getNode(ID);
            if (node == NULL) {
                last->next = new PrimeNode<ItemType>(ID, data);
                last = last->next;
            } else {
                node->subSLL->add(ID, data);
            }
        }
    }

    void del(PrimeNode<ItemType> *del) {
        PrimeNode<ItemType> *prev;
        if (isEmpty())
            return;
        PrimeNode<ItemType> *current = first;
        do {
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
