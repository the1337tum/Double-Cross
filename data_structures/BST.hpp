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

