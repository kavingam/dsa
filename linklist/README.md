<div align="center">
    <img src="https://img.shields.io/badge/C%2B%2B_DSA-GITHUB-RESOURCES?style=flat-square" alt="c++dsa">
    <img src="https://img.shields.io/badge/KAVINGAM-white?style=flat-square&logo=github&logoColor=black" alt="github">
</div>

## Introduction LinkList
**In C++,** a linked list is a linear data structure where elements, called nodes, are not stored in contiguous memory locations. Instead, each node contains two essential parts:

**Data:** This field holds the actual value stored in the node. It can be an integer, string, object, or any other data type you require.

**Next Pointer:** This pointer references the next node in the sequence. It's essentially an address that points to the memory location of the next node in the list. The last node's next pointer usually points to nullptr (null), indicating the end of the list.

**Types of Linked Lists:**

**Single Linked List:** The most common type. Each node has a data field and a next pointer that points to the following node in the list. Operations like insertion and deletion at the beginning are efficient, but operations in the middle can be slower due to the need to traverse the list.

**Circular Linked List:** In this variation, the last node's next pointer points back to the head node, creating a circular structure. This allows efficient traversal without reaching a null pointer as the list forms a loop.
Advantages:

**Dynamic Memory Allocation:** Nodes are allocated memory as needed at runtime, making linked lists flexible in size and suitable for scenarios where the data size is unknown beforehand.

**Efficient Insertion at the Beginning:** New nodes can be added at the head very quickly in both single and circular linked lists.

**Disadvantages:**

Slow Insertion/Deletion in the Middle: Finding a specific node requires traversing the list from the beginning, which can be inefficient for insertions or deletions in the middle, particularly in single linked lists.
Increased Memory Overhead: Compared to arrays, linked lists require additional memory for the pointer in each node.

**Applications:**

Linked lists are widely used in various scenarios where dynamic memory allocation and efficient insertion at the beginning are crucial. Here are some examples:

<p>Implementing stacks and queues (LIFO and FIFO data structures)</p>
<p>Representing graphs (connections between nodes)</p>
<p>Managing caches (storing frequently accessed data)</p>
<p>Implementing undo/redo functionality</p>

## single linked list in C++

**Concept:**

<p>A single linked list is a linear data structure where elements (nodes) are arranged in a sequential order. Each node contains two parts:</p>

**Data:** The actual value stored in the node.

**Next Pointer:** A pointer that references the next node in the list. The last node's next pointer points to nullptr (null), indicating the end of the list.

**Structure:**

```C++
struct Node {
  int data; // Data to be stored
  Node* next; // Pointer to the next node
};
```
<p>Use code with caution.</p>

**Operations:**

**Creation:** Allocate memory for a new node, set its data and next pointer (initially nullptr).

**Insertion:** Add a new node at the beginning, end, or a specific position in the list.

**Deletion:** Remove a node from the beginning, end, or a specific position in the list.

**Traversal:** Visit each node in the list, one after another, starting from the head.

**Searching:** Find a node with a specific value.

**Implementation:**

<i>C++ class representing a single linked list</i>
```C++
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
        std::cout<< tmp->data <<" ";
        temp = temp->next;
    }
  }
};
```
