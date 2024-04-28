#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
class singleLinkedList {
    private:
        Node *head;
    public:
        singleLinkedList() {
            head = nullptr;
        }
        void printList() {
            if(head != nullptr) {
                Node * temp = head;
                cout << "List is :";
                while(temp != nullptr) {
                    cout << temp->data << "->";
                    temp = temp->next;
                }
                cout << "null" <<endl;
                return;
            }
            cout << "Empty list" <<endl;  
            return;          
        }
        int coutNode() {
            int cnt = 0;
            if(head != nullptr) {
                Node * temp = head;
                while(temp != nullptr) {
                    cnt += 1;
                    temp = temp->next;
                }
            }
            return cnt;
        }
        bool search(int data) {
            if(head != nullptr) {
                Node * temp = head;
                while(temp != nullptr) {
                    if(temp->data == data) {
                        return true;
                    }
                    temp = temp->next;
                }
            }
            return false;
        }
        void insertAtFirst(int data) {
            Node * newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
        void insertAtLast(int data) {
            Node *newNode = new Node;
            newNode->data = data;
            Node *temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
        void insertAtPos(int data,int pos) {
            if(head == nullptr) {
                cout << "Empty list " <<endl;
                return;
            }
            Node * newNode = new Node;
            newNode->data = data;
            if(head->data == pos) {
                newNode->next = head;
                head = newNode;
                return;
            }
            Node * temp = head;
            while(temp->next->next != nullptr) {
                if(temp->next->data == pos) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            }
        }
        void insertAtAfter(int data,int pos) {
            if(head != nullptr) {
                Node * newNode = new Node;
                Node * temp = head;
                while(temp != nullptr) {
                    if(temp->data == pos) {
                        newNode->data = data;
                        newNode->next = temp->next;
                        temp->next = newNode;
                        return;
                    }
                    temp = temp->next;
                }
            }
        }
};
int main() {
    singleLinkedList mylist;
    // insert at first node
    mylist.insertAtFirst(1);
    mylist.insertAtFirst(2);
    mylist.insertAtFirst(3);
    mylist.insertAtLast(4);
    mylist.insertAtLast(5);
    // complex insertion method
    mylist.insertAtPos(10,1);
    mylist.insertAtAfter(11,2);
    mylist.printList();
    cout << "tottal number node " << mylist.coutNode() << endl;
    int searchValue = 3;
    if(mylist.search(searchValue)) {
        cout << searchValue << " value is found in list" <<endl;
    }
    else {
        cout << searchValue << " value is not found in list" <<endl;
    }
    return (0);
}
