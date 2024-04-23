#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct Node {
  int data;
  Node* prev;
  Node* next;

  Node(int data) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

// Doubly Linked List class with operations
class DoublyLinkedList {
 private:
  Node* head;

 public:
  DoublyLinkedList() {
    head = nullptr;
  }

  // Insert a new node at the beginning of the list
  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) {
      head->prev = newNode;
    }
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
    newNode->prev = temp;
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
    int currentPos = 0;

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

    // Insert at the end if temp is the last node
    if (temp->next == nullptr) {
      insertAtEnd(data);
      return;
    }

    // Update links for insertion in the middle
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
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
    if (head != nullptr) {
      head->prev = nullptr;
    }
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
  // Delete the node at a specific position
  void deleteAtPosition(int position) {
    if (position < 0) {
      cout << "Invalid position!" << endl;
      return;
    }

    // Delete the first node
    if (position == 0) {
      deleteFirst();
      return;
    }

    Node* temp = head;
    int currentPos = 0;

    // Find the node at the deletion position
    while (temp != nullptr && currentPos < position) {
      temp = temp->next;
      currentPos++;
    }

    // Check if position is beyond the list length
    if (temp == nullptr) {
      cout << "Position out of bounds!" << endl;
      return;
    }

    // Update links to bypass the deleted node
    if (temp->prev != nullptr) {
      temp->prev->next = temp->next;
    } else {
      head = temp->next;
    }
    if (temp->next != nullptr) {
      temp->next->prev = temp->prev;
    }
    delete temp;
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

  // Print the contents of the linked list (forward traversal)
  void printListForward() {
    Node* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
  // Reverse the linked list
  void reverse() {
    Node* temp = head;
    Node* current = nullptr;

    while (temp != nullptr) {
      // Swap next and prev pointers
      current = temp->prev;
      temp->prev = temp->next;
      temp->next = current;

      temp = temp->prev;
    }

    // Update head pointer to point to the new first node
    head = current;
  }
  // Print the contents of the linked list (backward traversal)
  void printListBackward() {
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->prev;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  DoublyLinkedList list;

  // Insert elements
  list.insertAtBeginning(5);
  list.insertAtEnd(3);
  list.insertAtBeginning(1);
  list.insertAtEnd(7);

  // Print the list forward
  cout << "List (forward): ";
  list.printListForward();

  // Print the list backward (optional)
  // cout << "List (backward): ";
  // list.printListBackward();

  return 0;
}
