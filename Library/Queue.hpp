/*	A fixed length cyclic queue template. */

template <typename ItemType>
struct QueueNode {
   ItemType data;
   QueueNode<ItemType> *next;
};

template <typename ItemType, int size>
class Queue {
private:
	QueueNode<ItemType> *first;
	QueueNode<ItemType> *last;
	QueueNode<ItemType> queue[size];

public:
	const int length = size;
	
	Queue() {
		first = NULL;
		last = NULL;
		for (int node = 0; node < length; node++)
			queue[node].next = &queue[(node + 1) % length];
	}

	~Queue() { /* No allocated memory */ }

                
	int isEmpty() { return first == NULL; }

	int isFull() { return last->next == first; }

	void put( ItemType item ) {
		if (isEmpty()) {
			first = queue;
			last = queue;
			first->data = item;
		} else if (isFull()) {
			return; 
		} else {
			last = last->next;
			last->data = item;
		}
	}

	ItemType get() {
		QueueNode<ItemType> *result;

		if (isEmpty()) { return NULL; }
		if (first == last) {
			result = first;
			last = first = NULL;
		} else {
			result = first;
			first = first->next;
		}
		return result->data;
	}

	ItemType peek() {
		if (!isEmpty()) { return first->data; }
	}
};
