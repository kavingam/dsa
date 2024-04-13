#include <iostream>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Array to store the stack elements
int stack[MAX_SIZE];

// Top index of the stack
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
  return top == -1;
}

// Function to check if the stack is full
bool isFull() {
  return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int data) {
  if (isFull()) {
    std::cout << "Stack overflow\n";
    return;
  }
  stack[++top] = data;
}

// Function to pop an element from the stack
int pop() {
  if (isEmpty()) {
    std::cout << "Stack underflow\n";
    return -1; // Or any invalid value to indicate error
  }
  return stack[top--];
}

int main() {
  push(10);
  push(20);
  push(30);

  std::cout << pop() << std::endl; // Output: 30
  std::cout << pop() << std::endl; // Output: 20

  return 0;
}

