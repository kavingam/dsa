#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct Node {
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

// Circular Linked List class with operations
class CircularLinkedList {
 private:
  Node* head;

 public:
  CircularLinkedList() {
    head = nullptr;
  }

  // Insert a new node at the beginning of the list
  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
      newNode->next = newNode;  // Set next to itself for the first node
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
  }

  // Insert a new node at the end of the list
  void insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
      newNode->next = newNode;  // Set next to itself for the first node
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }

  // Delete the first node in the list
  void deleteFirst() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    if (head->next == head) {
      delete head;
      head = nullptr;
      return;
    }
    Node* temp = head;
    while (temp->next->next != head) {
      temp = temp->next;
    }
    temp->next = head->next;
    delete head;
    head = temp->next;
  }

  // Search for a specific data value in the list
  bool search(int data) {
    if (head == nullptr) {
      return false;
    }
    Node* temp = head;
    do {
      if (temp->data == data) {
        return true;
      }
      temp = temp->next;
    } while (temp != head);
    return false;
  }

  // Print the contents of the linked list
  void printList() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    Node* temp = head;
    do {
      cout << temp->data << " -> ";
      temp = temp->next;
    } while (temp != head);
    cout << "NULL" << endl;
  }
};

int main() {
  CircularLinkedList list;

  // Insert elements
  list.insertAtBeginning(3);
  list.insertAtEnd(2);
  list.insertAtBeginning(1);

  // Print the list
  cout << "Circular Linked List: ";
  list.printList();

  // Search for a value
  int searchValue = 3;
  if (list.search(searchValue)) {
    cout << searchValue << " found in the list." << endl;
  } else {
    cout << searchValue << " not found in the list." << endl;
  }

  // Delete operations (example)
  list.deleteFirst();
  cout << "After deleting first node: ";
  list.printList();

  return 0;
}
