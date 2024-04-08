#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end
    void append(int new_data) {
        Node* new_node = new Node(new_data);
        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = new_node;
        new_node->prev = last;
    }

    // Function to insert a new node at a given position
    void insert_at_pos(int new_data, int pos) {
        if (pos < 0) {
            return; // Invalid position
        }

        Node* new_node = new Node(new_data);

        if (pos == 0) {
            new_node->next = head;
            if (head != nullptr) {
                head->prev = new_node;
            }
            head = new_node;
            return;
        }

        int count = 0;
        Node* current = head;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            return; // Position out of bounds
        }

        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != nullptr) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }

    // Function to print contents of list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList llist;

    // Insert 5 at the end
    llist.append(5);

    // Insert 7 at the beginning (position 0)
    llist.insert_at_pos(7, 0);

    // Insert 3 at position 2
    llist.insert_at_pos(3, 2);

    std::cout << "Created Doubly Linked List is: ";
    llist.printList();

    return 0;
}
