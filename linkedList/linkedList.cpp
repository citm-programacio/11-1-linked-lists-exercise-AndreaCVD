#include <iostream>
#include <cassert>

using namespace std;

// Declaration of a doubly-linked list
class List {
private:
	// Internal struct for list nodes
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};

	// List internals
	Node* first = nullptr;
	Node* last = nullptr;
	unsigned int num_elems = 0;

public:
	// Constructor which locates the first to nullptr to indicate that the list is initially empty
	//	last is also pointed to nullptr 'cause the list is empty so there's no last element yet,
	//	finally the num_elems has no elements, so it's 0.
	List() : first(nullptr), last(nullptr), num_elems(0) {};

	// Destructor using the clear() function.
	~List() {
		clear();
	};

	// Modifiers
	void push_front(const int& value);
	
	//	->push_back to insert elements at the back of the list
	void push_back(const int& value) {
		
		// If there's no elements, the first position will have the value
		if (num_elems == 0) {
			first = last = new Node;

			first->value = value;
			first->prev = nullptr;
			first->next = nullptr;
		}
		else {
			Node* node = new Node;
			node->value = value;
			node->prev = last;
			last->next = node;
			last = node;
		}
		num_elems++;
	};
	void pop_front();
	void pop_back();

	//	->insert function to insert nums
	void insert(unsigned int position, const int& value) {
	

	};
	void erase(unsigned int position);
	void clear();

	// Getters
	int& front();
	int& back();
	int& value_at(unsigned int position);
	bool empty() const;
	unsigned int size() const;

};



int main()
{
	List mevaLlista;

	mevaLlista.insert(0, 5);
	mevaLlista.print();
}