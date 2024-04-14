#include <iostream>
struct Node {
    int data;
    Node* prev;
    Node* next;
};
class DoubleLinkedList {
    private:
        Node *head; // Pointer to the head
    public:
    DoubleLinkedList() {
        head = nullptr; // Initially, the list is empty
    }
    // Function to insert a new node at the beginning
    void first_node(int new_data) {
        Node * new_node = new Node;
        new_node->data = new_data;
        new_node->prev = nullptr;
        new_node->next = head;

        if(head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
    }
    // Function to print contents of list
    void printList() {
        Node* temp = head;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    DoubleLinkedList obj;
    obj.first_node(1);
    obj.printList();
    return 0;
}