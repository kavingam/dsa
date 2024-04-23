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

  // Insert a new node at a specific position
  void insertAtPosition(int data, int position) {
    if (position < 0) {
      cout << "Invalid position!" << endl;
      return;
    }

    // Insert at beginning
    if (position == 0) {
      insertAtBeginning(data);
      return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int currentPos = 1;

    // Find the node before the insertion position
    while (temp != nullptr && currentPos < position) {
      temp = temp->next;
      currentPos++;
    }

    // Check if position is beyond the list length
    if (temp == nullptr) {
      cout << "Position out of bounds!" << endl;
      return;
    }

    newNode->next = temp->next;
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

  // Reverse the linked list
  void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    while (current != nullptr) {
      next = current->next;  // Store the next node
      current->next = prev;  // Reverse the link
      prev = current;       // Move pointers one step
      current = next;
    }

    head = prev;  // Update the head pointer to point to the new first node
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
  cout << "Original List: ";
  list.printList();

}