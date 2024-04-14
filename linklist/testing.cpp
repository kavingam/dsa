#include <iostream>

struct Node {
	int data;
	Node* next;
};

class SingleLinkedList {
private:
  Node* head; // Pointer to the head node

public:
  SingleLinkedList() {
    head = nullptr; // Initialize head to nullptr (empty list)
  }

  // Check if the list is empty
  bool isEmpty() const {
    return head == nullptr;
  }

  // Insert a node at the beginning of the list
  void insertAtBeginning(int value) {
    Node* newNode = new Node; // Create a new node
    newNode->data = value;
    newNode->next = head; // Make the new node point to the current head
    head = newNode; // Update head to point to the newly inserted node
  }

  // Insert a node at the end of the list
  void insertAtEnd(int value) {
    Node* newNode = new Node; // Create a new node
    newNode->data = value;
    newNode->next = nullptr; // Set the new node's next to nullptr (last node)

    if (isEmpty()) { // Handle empty list case
      head = newNode;
      return;
    }

    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
      temp = temp->next;
    }
    temp->next = newNode; // Update the last node's next to point to the new node
  }

  // Delete the node at the beginning of the list
  int deleteAtBeginning() {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return -1; // Or throw an exception
    }

    Node* temp = head;
    int data = temp->data;
    head = head->next; // Update head to point to the next node
    delete temp;
    return data;
  }

  // Delete the last node of the list
  int deleteAtEnd() {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return -1; // Or throw an exception
    }

    if (head->next == nullptr) { // Handle single node case
      int data = head->data;
      delete head;
      head = nullptr;
      return data;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while (temp->next != nullptr) {
      prev = temp;
      temp = temp->next;
    }

    prev->next = nullptr; // Update the second-last node's next to nullptr
    int data = temp->data;
    delete temp;
    return data;
  }

  // Traverse the list and print data
  void traverse() const {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        std::cout<< temp->data <<" ";
        temp = temp->next;
    }
  }
};
int main() {
	
	return 0;
}