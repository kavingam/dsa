/*Single Linked List ESCP1R - 1*/
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList {
    private:
        Node * head;
    public:
        LinkedList() {
            head = nullptr;
        }
        void insertAtBeginnig(int data) {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        void insertAtEnd(int data) {
            Node *newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                return;
            }
            Node * temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        void insertAtPos(int data,int position) {
            if(position < 0) {
                cout << "invalid position !"<<endl;
                return;
            } 
            // insert beginning 
            if(position == 0) {
                insertAtBeginnig(data);
                return;
            }
            Node * newNode = new Node(data);
            Node * temp = head;
            int currentPos = 1;
            while(temp!=nullptr && currentPos < position) {
                temp = temp->next;
                currentPos ++;
            }
            if(temp == nullptr) {
                cout << "position out of bound !"<<endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        void deleteFirst() {
            if(head == nullptr) {
                cout << "List is empty"<<endl;
                return;
            }
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        void deleteLast() {
            if(head == nullptr) {
                cout << "List is empty" << endl;
                return;
            }
            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            Node * temp = head;
            while(temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        void deleteAtPos(int position) {
            if(position < 0) {
                cout << "invalid position !"<<endl;
                return;
            }
            // delete the first node
            if(position == 0) {
                deleteFirst();
                return;
            }
            Node *temp = head;
            Node *prev = nullptr;
            int currentPos = 0;
            while(temp != nullptr && currentPos < position) {
                prev = temp;
                temp = temp->next;
                currentPos ++;
            }
            if(temp == nullptr) {
                cout<<"position out of bounds" <<endl;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
        void reverse() {
            Node * prev = nullptr;
            Node *current = head;
            Node * next;
            while(current!=nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }

        bool search(int data) {
            Node *temp = head;
            while(temp!=nullptr) {
                if(temp->data == data) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
        void printList() {
            Node * temp = head;
            while(temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" <<endl;
        }
};
int main() {
    LinkedList list;
    list.insertAtBeginnig(1);
    list.insertAtBeginnig(2);
    list.insertAtEnd(11);
    list.insertAtEnd(12);
    list.insertAtPos(10,2);
    list.printList();

    list.deleteFirst();
    list.deleteLast();
    list.deleteAtPos(2);
    list.printList();

    list.reverse();
    list.printList();

    int searchValue = 1;
    if(list.search(searchValue)) {
        cout << searchValue << " found in the list." <<endl;
    }
    else {
        cout << searchValue << " not found in the list." << endl;
    }
    return 0;
}