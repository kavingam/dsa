#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
  int maxSize; // Maximum size of the stack
  int top; // Index of the top element
  int* data; // Array to store stack elements

public:
  // Constructor to initialize the stack
  Stack(int size) {
    if (size <= 0) {
      throw invalid_argument("Stack size must be positive");
    }
    maxSize = size;
    top = -1; // Initially stack is empty
    data = new int[maxSize];
  }

  // Destructor to free memory allocated for the array
  ~Stack() {
    delete[] data;
  }

  // Push an element onto the stack
  void push(int value) {
    if (isFull()) {
      throw overflow_error("Stack overflow");
    }
    data[++top] = value;
  }

  // Pop an element from the stack
  int pop() {
    if (isEmpty()) {
      throw underflow_error("Stack underflow");
    }
    return data[top--];
  }

  // Check if the stack is empty
  bool isEmpty() const {
    return top == -1;
  }

  // Check if the stack is full
  bool isFull() const {
    return top == maxSize - 1;
  }

  // Peek at the top element without removing it
  int peek() const {
    if (isEmpty()) {
      throw underflow_error("Stack underflow");
    }
    return data[top];
  }

  // Print the contents of the stack
  void printStack() const {
    if (isEmpty()) {
      cout << "Stack is empty!" << endl;
      return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
      cout << data[i] << " -> ";
    }
    cout << "NULL" << endl;
  }
};

int main() {
  Stack stack(5); // Create a stack with maximum size 5

  // Push elements onto the stack
  stack.push(10);
  stack.push(20);
  stack.push(30);

  // Print the stack
  stack.printStack();

  // Pop elements from the stack
  cout << "Popped element: " << stack.pop() << endl;
  cout << "Popped element: " << stack.pop() << endl;

  // Check if stack is empty
  if (stack.isEmpty()) {
    cout << "Stack is empty!" << endl;
  } else {
    cout << "Stack is not empty." << endl;
  }

  return 0;
}

/*
This program defines a Stack class with the following functionalities:

Constructor: Initializes the stack with a maximum size.
Destructor: Frees memory allocated for the array.
push(int value): Pushes an element onto the stack (throws an exception if full).
pop(): Pops an element from the stack (throws an exception if empty).
isEmpty(): Checks if the stack is empty.
isFull(): Checks if the stack is full.
peek(): Returns the top element without removing it (throws an exception if empty).
printStack(): Prints the contents of the stack.

*/