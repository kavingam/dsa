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
            node *ptr,*tmp;
            ptr = head;
            while(ptr != NULL){
                if(ptr->data == item){
                    tmp = new node;
                    tmp->data = data;
                    tmp->next = ptr->next;
                    ptr->next = tmp;
                }
                ptr=ptr->next;
            }
        }
        /*function addbefore() insert a new node at the before the node*/
        void addbefore(int data,int item){
            node *tmp,*ptr;

			if(head->data == item){
				tmp = new node;
				tmp->data = data;
				tmp->next = head;
				head = tmp;
			}		

			ptr=head;
			while(ptr->next != NULL){
				if(ptr->next->data == item){
					// cout<<ptr->data<<"\n"<<ptr->next->data<<"\n";
					tmp = new node;
					tmp->data = data;
					tmp->next = ptr->next;
					ptr->next = tmp;
					break;
				}
				ptr=ptr->next;
			}				
		}
};
int main() {
    single obj;
    /*create list single linked list*/
    for(int i= 0;i < 10;i++){
        if(i == 0){
            obj.addbeg(i);
        }
        else {
            obj.addend(i);
        }
    }
    /*function display() call*/
   obj.addafter(78,6);
    obj.addbefore(75,6);
    obj.display();
    return 0;
}