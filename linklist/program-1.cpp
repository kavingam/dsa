#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
};
class single{
    private: 
        node *head;
    public:
        single(){
            head = NULL;
        }
        /**/
        void display(){
            node *ptr = head;
            if(head == NULL){
                cout<<"empty list"<<endl;
                return;
            }
            cout<<"list is: ";
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
        }
        /*function addbeg() adds a node at the beggining of the list*/ 
        void addbeg(int data){
            node *ptr = new node;
            ptr->data = data;
            ptr->next = head;
            head = ptr;
        }
        /*function addend() insert a node at the end of the list*/
        void addend(int data){
            node *ptr = new node;
            ptr->data = data;
            node *tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = ptr;
            ptr->next = NULL;
        }
        /*function addafter() insert a new node at the after the node */
        void addafter(int data,int item){
            node *tmp,*ptr = new node;
        }
};
int main() {
    single obj;
    obj.addbeg(1);
    obj.addbeg(2);
    // obj.addend(3);
    obj.display();
    return 0;
}