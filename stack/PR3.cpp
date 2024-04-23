#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(const T& element) {
        elements.push_back(element);
    }
    
    void pop() {
        if (!empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }
    
    const T& top() const {
        if (!empty()) {
            return elements.back();
        } else {
            cout << "Stack is empty. Cannot retrieve top element." << endl;
            exit(1); // Exiting due to error, you might handle this differently in your actual application
        }
    }
    
    bool empty() const {
        return elements.empty();
    }
    
    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    myStack.pop();
    cout << "Stack size after popping: " << myStack.size() << endl;
    cout << "Top element after popping: " << myStack.top() << endl;

    return 0;
}
