#include <iostream>

#define MAX_SIZE 100 // Define a maximum size for the stack

class Stack {
private:
  int arr[MAX_SIZE];
  int top;

public:
  Stack() {
    top = -1; // Initialize top to -1 (empty stack)
  }

  bool isEmpty() const {
    return top == -1;
  }

  bool isFull() const {
    return top == MAX_SIZE - 1;
  }

  void push(int value) {
    if (isFull()) {
      std::cout << "Stack Overflow\n";
      return;
    }
    arr[++top] = value;
  }

  int pop() {
    if (isEmpty()) {
      std::cout << "Stack Underflow\n";
      return -1; // Or throw an exception
    }
    return arr[top--];
  }

  int peek() const {
    if (isEmpty()) {
      std::cout << "Stack is empty\n";
      return -1; // Or throw an exception
    }
    return arr[top];
  }
};

int main() {
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);

  std::cout << s.pop() << std::endl; // Output: 30
  std::cout << s.peek() << std::endl;  // Output: 20

  return 0;
}
// code end