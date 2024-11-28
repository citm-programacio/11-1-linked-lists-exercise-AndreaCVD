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

	//	->push_front to insert elements at the start of the list
	void push_front(const int& value) {

		if (num_elems == 0)
		{
			first = last = new Node;
			first->value = value;
			first->prev = nullptr;
			first->next = nullptr;
		}
		else
		{
			Node* node = new Node;
			node->value = value;
			node->prev = nullptr;
			node->next = first;
			first->prev = node;
			first = node;
		}
		num_elems++;
	};
	
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
			node->next = nullptr;
			
			last->next = node;
			last = node;
		}
		num_elems++;
	};
	
	void pop_front();
	void pop_back();

	//	->insert function to insert nums
	void insert(unsigned int position, const int& value) {

		// check if the position is valid within the bounds of the list
		if (position > num_elems) {
			cout << "Position is out of bounds" << endl;
			return;
		}

		// insert depeneding the position:
		if (position == 0) { //->at the start
			push_front(value);
			return;
		} 
		
		if (position == num_elems) { //->at the back
			push_back(value);
			return;
		}

		// if it's a specific position 
		Node* node = new Node;
		node->value = value;

		Node* current = first;
		//	position - 1 is th node before the specific position 
		for (unsigned int i = 0; i < position - 1; i++) {
			current = current->next;
		}

		// insert between current and current->next
		node->next = current->next;
		node->prev = current;

		if (current->next != nullptr) { // if it exist we update the prev node
			current->next->prev = node;
		}
		
		current->next = node; //update the next one to the actual node with the new position

		num_elems++;

	};
	void erase(unsigned int position);

	//	->clear the list and free memory
	void clear() {

		// this will allow to check each node as the loop goes.
		Node* current = first;

		// this one will allow us no not lose track of the next node as we delete the current one
		Node* nextNode = nullptr;

		// delete each node
		while (current != nullptr) {

			// we save the next one
			nextNode = current->next;

			// delete the current one
			delete current;

			// we move the current node to the next one so the loop can continue till it's empty
			current = nextNode;
		}

		// and reset
		first = last = nullptr;
		num_elems = 0;

	};

	// Getters
	int& front();
	int& back();
	int& value_at(unsigned int position);
	bool empty() const;
	unsigned int size() const;

	void print() const {

		Node* it = first;

		while (it != nullptr)
		{
			cout << it->value << " | ";
			it = it->next;
		}
	};

};



int main()
{
	List mevaLlista;

	mevaLlista.insert(2, 5);
	mevaLlista.insert(0, 0);
	mevaLlista.insert(1, 1);
	mevaLlista.insert(2, 2);
	mevaLlista.print();

	cout << endl;

	mevaLlista.insert(1, 3);
	mevaLlista.print();

	cout << endl;

	mevaLlista.insert(0, 4);
	mevaLlista.insert(4, 5);
	mevaLlista.print();

}