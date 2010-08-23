/**
 * This is a two dimensional queue, that has been modified
 * to store:
 *      int hash;
 *      char *string;
**/

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
class PrimeQueue {
private:
        PrimeNode *first;
	PrimeNode *last;
	PrimeNode queue[length];

public:
	const int length;
	
	PrimeQueue(int size) : length(size) {
		first = NULL;
		last = NULL;
		for (int node = 0; node < length; node++)
			queue[node].next = &queue[(node + 1) % length];
	}
        
	~PrimeQueue() {
            PrimeNode *current = first;
            while(current != NULL) {
                PrimeNode *next = current.next;
                delete current;
            }
        }
         
	int isEmpty() { return first == NULL; }

	int isFull() { return last->next == first; }
        
	void put(int hash, char *string) {
		if (isEmpty()) {
			first = queue;
			last = queue;
			first = new PrimeNode(hash, string);
		} else if (isFull()) {
			return; 
		} else {
			last = last->next;
			last = new PrimeNode(hash, string);
		}
	}

	const PrimeNode *get() {
		PrimeNode *result;

		if (isEmpty()) { return NULL; }
		if (first == last) {
			result = first;
                        delete first;
			last = first = NULL;
		} else {
			result = first;
                        PrimeNode *del = first;
			first = first->next;
                        delete del;
		}
		return result->data;
	}

	const PrimeNode *peek() {
		if (!isEmpty()) { return first->data; }
	}

};

// The queue node to store the string to the hash.
struct SubNode {
   char *string;
   node *next;

    // optional constructor and destructor
    node(char *copy, SubNode *next) {
        this.next = next;  
        this.string = emalloc(strlen(copy));
        strcpy(string, copy);
    }
    ~node() { free(data); }
};

// The inner hashQueue
class SubQueue {
private:
	SubNode *first;
	SubNode *last;
	SubNode queue[length];

public:
	const int length;
	
	SubQueue(int size) : length(size) {
		first = NULL;
		last = NULL;
		for (int node = 0; node < length; node++)
			queue[node].next = &queue[(node + 1) % length];
	}
        
	~SubQueue() {
            SubNode *current = first;
            while(current != NULL) {
                Node *next = current.next;
                delete current;
            }
        }
         
	int isEmpty() { return first == NULL; }

	int isFull() { return last->next == first; }
        
	void put(char *string) {
		if (isEmpty()) {
			first = queue;
			last = queue;
			first = new SubNode(string);
		} else if (isFull()) {
			return; 
		} else {
			last = last->next;
			last = new Node(string);
		}
	}

	SubNode *get() {
		SubNode *result;

		if (isEmpty()) { return NULL; }
		if (first == last) {
			result = first;
                        delete first;
			last = first = NULL;
		} else {
			result = first;
                        Node *del = first;
			first = first->next;
                        delete del;
		}
		return result->string;
	}

	SubNode *peek() {
		if (!isEmpty()) { return first->string; }
	}

};

