#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push element." << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop element." << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element to peek." << endl;
            return -1; // Error value, you might handle this differently in your application
        }
        return arr[top];
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element: " << myStack.peek() << endl;

    myStack.pop();
    cout << "Top element after popping: " << myStack.peek() << endl;

    return 0;
}
