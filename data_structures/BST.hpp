/**
 * A simple Binary Search Tree (BST).
 * No fancy rotations, so worst case is O(n); not O(log n)
 * like you might expect from an RBT. But have a lower cost 
 * for insertions and deletions, so useful for smaller datasets.
**/

class BSTNode {
private:
    int value;
    BSTNode *left;
    BSTNode *right;

    int minValue();
public:
    BSTNode(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
    ~BSTNode() { /* No heap memory */ }

    // Accessors
    bool search(int value);
    int getValue();
    BSTNode *getLeft();
    BSTNode *getRight();
    
    // Mutators
    bool add(int value);
    BSTNode *remove(int value, BSTNode *parent);
};
 
class BinarySearchTree {
private:
    BSTNode *root;
public:
    BinarySearchTree() {
        root = NULL;
    }

    bool search(int value);
    bool add(int value);
    bool remove(int value);
};

