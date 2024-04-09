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

  // Delete the node at the beginning of the list
  int deleteAtBeginning() {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return -1; // Or throw an exception
    }

    Node* temp = head;
    int data = temp->data;

    if (head == head->next) { // Handle single node case
      head = nullptr;
    } else {
      head = head->next;
      temp->next = head->next; // Update last node's next
    }
    delete temp;
    return data;
  }

  // Delete the node at the end of the list
  int deleteAtEnd() {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return -1; // Or throw an exception
    }

    Node* temp = head;
    Node* prev = nullptr;

    if (head == head->next) { // Handle single node case
      int data = head->data;
      delete head;
      head = nullptr;
      return data;
    }

    while (temp->next != head) {
      prev = temp;
      temp = temp->next;
    }
    prev->next = head;
    int data = temp->data;
    delete temp;
    return data;
  }

  // Traverse and print the list
  void printList() const {
    if (isEmpty()) {
      std::cout << "List is empty\n";
      return;
    }

    Node* temp = head;
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
  list.printList(); // Output: 5 10 20 30

  list.deleteAtBeginning();
  std::cout << "After deleting from beginning: ";
  list.printList(); // Output: 10 20 30

  list.deleteAtEnd();
  std::cout << "After deleting from end: ";
  list.printList(); // Output: 10 20

  return 0;
}
