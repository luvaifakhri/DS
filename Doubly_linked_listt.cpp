#include <iostream>
using namespace std;
// Define a struct named Node to represent a node in the doubly linked list.
struct Node {
	int data; // Data part of the node.
	Node* next; // Pointer to the next node.
	Node* prev; // Pointer to the previous node.
	// Constructor to initialize the node with given data.
	Node(int data_val) {
		data = data_val;
		next = NULL;
		prev = NULL;
	}
};

// Function to insert a node at the beginning of the doubly linked list.
void insertAtBeginning(Node*& head, int data) {
	Node* newNode = new Node(data);
	newNode->next = head;
	if (head != NULL) {
		head->prev = newNode;
	}
	head = newNode;
}

// Function to insert a node at the end of the doubly linked list.
void insertAtEnd(Node*& head, int data) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

// Function to delete a node from the beginning of the doubly linked list.
void deleteFromBeginning(Node*& head) {
	if (head == NULL) {
		cout << "List is empty. Cannot delete from beginning." << endl;
		return;
	}
	Node* temp = head;
	head = head->next;
	
	if (head != NULL) {
		head->prev = NULL;
	}
	delete temp;
}
// Function to delete a node from the end of the doubly linked list.
void deleteFromEnd(Node*& head) {
	if (head == NULL) {
		cout << "List is empty. Cannot delete from end." << endl;
		return;
	}
	if (head->next == NULL) { // Only one node in the list
		delete head;
		head = NULL;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;
}

// Function to display the doubly linked list from head to tail.
void displayForward(Node* head) {
	Node* temp = head;
	cout << "Doubly Linked List (Forward): ";
	while (temp != NULL) {
		cout << temp->data << " <-> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}
// Function to display the doubly linked list from tail to head.
void displayBackward(Node* head) {
	if (head == NULL) {
		cout << "Doubly Linked List (Backward): nullptr" << endl;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	std::cout << "Doubly Linked List (Backward): ";
	while (temp != NULL) {
		cout << temp->data << " <-> ";
		temp = temp->prev;
	}
	cout << "NULL" << endl;
}
int main() {
	Node* head = NULL; // Initialize head of the doubly linked list
	insertAtBeginning(head, 3);
	insertAtBeginning(head, 2);
	insertAtBeginning(head, 1);
	displayForward(head); // Output: 1 <-> 2 <-> 3 <-> nullptr
	insertAtEnd(head, 4);
	insertAtEnd(head, 5);
	displayForward(head); // Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> nullptr
	displayBackward(head); // Output: 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> nullptr
	deleteFromBeginning(head);
	displayForward(head); // Output: 2 <-> 3 <-> 4 <-> 5 <-> nullptr
	deleteFromEnd(head);
	displayForward(head); // Output: 2 <-> 3 <-> 4 <-> nullptr
return 0;
}
