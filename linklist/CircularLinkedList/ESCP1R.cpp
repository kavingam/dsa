#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
class CircularLinkedList {
    private:
        Node * head;
    public:
        CircularLinkedList() {
            head = nullptr;
        }
        void insertAtFirst(int data) {
            Node *newNode = new Node(data);
            if(head == nullptr) {
                newNode->next = newNode;
                head = newNode;
                return;
            }
        }
        void insertAtEnd(int data) {
            Node *newNode = new Node(data);
        }
        void printList() {
            if(head == nullptr) {
                cout << "Empty List :" <<endl; 
            }
            Node *temp = head;
            while(temp->next != head) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};
int main() {
    CircularLinkedList list;
    list.insertAtFirst(1);
    // list.insertAtEnd(2);
    list.printList();
    return 0;
}