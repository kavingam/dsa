#include <iostream>

struct Node {
  int data;
  Node* next;
};

class CircularLinkedList {
private:
  Node* head;

public:
  CircularLinkedList() {
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

    if (isEmpty()) { // Handle empty list case
      newNode->next = newNode;
    } else {
      newNode->next = head->next;
      head->next = newNode;
    }
    head = newNode; // Update head to point to the newly inserted node
  }

  // Insert a node at the end of the list
  void insertAtEnd(int value) {
    Node* newNode = new Node; // Create a new node
    newNode->data = value;

    if (isEmpty()) { // Handle empty list case
      newNode->next = newNode;
      head = newNode;
      return;
    }

    Node* temp = head;
    while (temp->next != head) { // Traverse to the last node
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }

  // Traverse the list and print data
  void traverse() const {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return;
    }

    Node* temp = head;

    // **Traversal condition:** Keep iterating until we reach the starting node again
    do {
      std::cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);

    std::cout << std::endl;
  }
};

int main() {
  CircularLinkedList list;
  list.insertAtBeginning(10);
  list.insertAtEnd(20);
  list.insertAtBeginning(5);
  list.insertAtEnd(30);

  std::cout << "List: ";
  list.traverse(); // Output: 5 10 20 30

  return 0;
}
