# introduction stack

**In C++,** a stack is a linear data structure that follows the Last In, First Out (LIFO) principle.  Imagine a stack of plates: the last plate you put on the stack is the first one you can take off.

C++ provides a built-in stack implementation in the Standard Template Library (STL) called std::stack. This implementation uses a class to encapsulate the stack functionality and offers various methods for interacting with the stack.

Here's a breakdown of key aspects of stacks in **C++:**

**LIFO Principle:**

Elements are added and removed from the same end, called the top of the stack.
The element pushed onto the stack last will be the first one popped (removed) from the stack.
Basic Operations:

**push(data):** Adds an element (data) to the top of the stack

**pop():** Removes and returns the element from the top of the stack.

**top():** Returns the element at the top of the stack without removing it.

**empty():** Checks if the stack is empty (returns true if empty).

**size():** Returns the number of elements in the stack.

**Applications of Stacks in C++:**

**Function call stack:** When a function is called, its arguments and local variables are pushed onto a stack. When the function returns, its information is popped from the stack.

**Expression evaluation:** Stacks are used to evaluate postfix expressions and convert infix expressions to postfix.

**Backtracking algorithms:** Stacks are used to keep track of paths explored in algorithms that need to explore multiple possibilities (e.g., maze solving).

**Undo/redo functionality:** Stacks can be used to implement undo/redo functionality in applications.


```Using std::stack:
#include <iostream>
#include <stack>

int main() {
  std::stack<int> myStack;

  myStack.push(10);
  myStack.push(20);

  std::cout << myStack.top() << std::endl; // Output: 20 (top element)

  myStack.pop();

  std::cout << myStack.top() << std::endl; // Output: 10 (new top element)

  return 0;
}
```
