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

    // Function to reverse the list
    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        // Swap next and prev pointers for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // Change head to point to the last node
        if (temp != nullptr) {
            head = temp;
        }
    }

    // Function to search for a value
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true; // Value found
            }
            current = current->next;
        }
        return false; // Value not found
    }

    // Function to count the number of nodes
    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
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

    // Function to delete the first node
    void delete_first() {
        if (head == nullptr) {
            return; // List is empty
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Function to delete the last node
    void delete_last() {
        if (head == nullptr) {
            return; // List is empty
        }

        if (head->next == nullptr) { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head;
        while (last->next->next != nullptr) {
            last = last->next;
        }

        Node* temp = last->next;
        last->next = nullptr;
        delete temp;
    }
    // Function to delete a node at a given position
    void delete_at_pos(int pos) {
        if (pos < 0) {
            return; // Invalid position
        }

        if (head == nullptr) {
            return; // List is empty
        }

        if (pos == 0) {
            delete_first();
            return;
        }

        int count = 0;
        Node* current = head;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr || current->next == nullptr) {
            return; // Position out of bounds or deleting last node
        }

        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = current;
        }
        delete temp;
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
    //llist.append(5);

    // Insert 7 at the beginning (position 0)
    //llist.insert_at_pos(7, 0);

    // Insert 3 at position 2
    //llist.insert_at_pos(3, 2);



    // llist.append(5);
    // llist.append(6);
    // llist.append(7);

    // std::cout << "Created Doubly Linked List: ";
    // llist.printList();

    // llist.delete_first();
    // std::cout << "After deleting first node: ";
    // llist.printList();

    // llist.delete_last();
    // std::cout << "After deleting last node: ";

    //std::cout << "Created Doubly Linked List is: ";    
//    llist.printList();
    // llist.append(5);
    // llist.append(6);
    // llist.append(7);
    // llist.append(8);

    // std::cout << "Created Doubly Linked List: ";
    // llist.printList();

    // llist.delete_at_pos(2);
    // std::cout << "After deleting at position 2: ";
    llist.append(5);
    llist.append(6);
    llist.append(7);
    llist.append(8);

    std::cout << "Created Doubly Linked List: ";
    llist.printList();

    llist.reverse();
    std::cout << "Reversed List: ";
    llist.printList();

    int search_value = 7;
    if (llist.search(search_value)) {
        std::cout << search_value << " found in the list.\n";
    } else {
        std::cout << search_value << " not found in the list.\n";
    }

    int node_count = llist.count();
    std::cout << "Number of nodes: " << node_count << std::endl;

    return 0;
}
