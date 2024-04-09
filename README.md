<div align="center">
    <img src="https://img.shields.io/badge/C%2B%2B_DSA-GITHUB-RESOURCES?style=flat-square" alt="c++dsa">
    <img src="https://img.shields.io/badge/KAVINGAM-white?style=flat-square&logo=github&logoColor=black" alt="github">
</div>

<details>
    <summary>table of content</summary>
    <ol>
        <li>
            <a alt="" href="">Chapter1 .Introduction</a>
            <ul>
                <li>
                    <a alt="" href="">1.1 Data Type</a>
                </li>
                <li>
                    <a alt="" href="">1.2 Abstract Data Type</a>
                </li>
                <li>
                    <a alt="" href="">1.3 Data Structures</a>
                    <ul>
                        <a alt="" href="">1.3.1 Linear and Non linear data structure</a>
                    </ul>
                    <ul>
                        <a alt="" href="">1.3.2 Static and dynamic data structure</a>
                    </ul>
                </li>
                <li>
                    <a alt="" href="">1.4 Algorithms</a>
                    <ul>
                        <a alt="" href="">1.4.1 Greedy algorithm</a>
                    </ul>
                    <ul>
                        <a alt="" href="">1.4.2 Divide and conquer algorithm</a>
                    </ul>
                    <ul>
                        <a alt="" href="">1.4.3 Backtracking</a>
                    </ul>
                    <ul>
                        <a alt="" href="">1.4.4 Randomized algorithm</a>
                    </ul>
                </li>
                <li>
                    <a alt="" href="">1.5 Analysis of algorithms</a>
                    <ul>
                        <a alt="" href="">1.5.1 Big O notation</a>
                    </ul>
                    <ul>
                        <a alt="" href="">1.5.1.1 Rule for O notation</a>
                    </ul>
                </li>
            </ul>
        </li>
        <li>
            <a alt="" href="">Chapter 2. Arrays,Pointers and Structures</a>
            <ul>
                <a alt="" href=""></a>
                <a alt="" href=""></a>
            </ul>
        </li>
        <li>
            <a alt="" href=""></a>
            <ul>
                <a alt="" href=""></a>
                <a alt="" href=""></a>
            </ul>
        </li>
        <li>
            <a alt="" href=""></a>
            <ul>
                <a alt="" href=""></a>
                <a alt="" href=""></a>
            </ul>
        </li>
    </ol>
</details>

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
}
```
