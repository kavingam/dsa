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
        /*creation of a single link list*/
        /*
        void create_list(){
            int i,n,data;
            printf("Enter the number of nodes :");
            scanf("%d",&n);
            if(n==0){
                return;
            }
            printf("enter the element to be inserted : ");
            scanf("%d",&data);
            addbeg(data);
            for(i=0;i<=n;i++){
                printf("enter the element to be inserted : ");
                scanf("%d",&data);
                head = addend(data);
            }
            return;

        }
        */
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
        /*function addpos() insert a new node at the given pos*/
        void addpos(int data,int pos){
            node *tmp,*ptr;
            int i;
            tmp = new node;
            tmp->data = data;
            if(pos == 1){
                tmp->next = head;
                head = tmp;
                return;
            }
            ptr = head;
            for(i=1;i<pos-1&&ptr!=NULL;i++){
                ptr=ptr->next;
            }
            if(ptr==NULL){

            }
            else {
                tmp->next = ptr->next;
                ptr->next = tmp;
            }
        }
        /*function reveres() */
        void reverse(){
            node *next,*ptr,*prev;
            prev = NULL;
            ptr = head;
            while(ptr!=NULL){
                next = ptr->next;
                ptr->next = prev;
                prev = ptr;
                ptr = next;
            }
            head = prev;
        }
        /*function  delete a first node and between node*/
        void delbeg(){
            if(head!=NULL){
                 node *tmp = head;
                 head = head->next;
                 free(tmp);
            }
        }
        /*function delete a end node*/ 
        void delend(){

        }
        /*function delete a given position node value*/
        void delpos(int data){
            node *tmp,*ptr;
            if(head == NULL){
                cout<<"List is empty\n";
                return;
            }
            if(head->data == data){
                tmp = head;
                head = head->next;
                free(tmp);
                return;
            }
            ptr = head;
            while(ptr->next!=NULL){
                if(ptr->next->data==data){
                    tmp = ptr->next;
                    ptr->next = tmp->next;
                    free(tmp);
                    return;
                }
                ptr=ptr->next;
            }
            printf("element %d not found\n",data);
            return;
        }
        /*End od delpos function*/
};
int main() {
    single obj;
    int n,i,choice,data,pos;
    while(true){
        cout<<"01.create list\n02.display\n03.count\n04.count\n05.search\n06.addbeg / add empty\n07.addend\n08.addpos\n09.delbeg\n10.delend\n11.delpos\n12.reseve\n13.quit\n\nenter your choice:";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"enter the node to be inserted :";
                cin>>n;
                if(n==0){
                    
                }
                cout<<"enter the element to be inserted : ";
                cin>>data;
                obj.addbeg(data);
                for(i=2;i<=n;i++){
                    cout<<"enter the element to be inserted : ";
                    cin>>data;
                    obj.addend(data);
                }
                break;
            }
            case 2:{
                obj.display();
                break;
            }
            case 13:{
                exit(1);
            }
            default:{
                cout<<"wrong choice\n";
            }
        }
    }
    return 0;
}