#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

// Linked List class with operations
class LinkedList {
 private:
  Node* head;

 public:
  LinkedList() {
    head = nullptr;
  }

  // Insert a new node at the beginning of the list
  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  // Insert a new node at the end of the list
  void insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  // Delete the first node in the list
  void deleteFirst() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  // Delete the last node in the list
  void deleteLast() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  // Search for a specific data value in the list
  bool search(int data) {
    Node* temp = head;
    while (temp != nullptr) {
      if (temp->data == data) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  // Print the contents of the linked list
  void printList() {
    Node* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList list;

  // Insert elements
  list.insertAtBeginning(5);
  list.insertAtEnd(3);
  list.insertAtBeginning(1);
  list.insertAtEnd(7);

  // Print the list
  cout << "Linked List: ";
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

  list.deleteLast();
  cout << "After deleting last node: ";
  list.printList();

  return 0;
}
