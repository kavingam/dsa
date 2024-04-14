#include <iostream>
using namespace std;
struct node {
    int data;
    node *prev;
    node *next;
};
class DoubleLinkList{

};
int main() {
    node *first_node = new node();
    first_node->data = 1;
    first_node->prev = NULL;
    
    node *second_node = new node();
    second_node->data = 2;
    second_node->prev = first_node;
    second_node->next = NULL;
    first_node->next = second_node;

    while(first_node != NULL){
        cout<<first_node->data<<" ";
        first_node = first_node->next;
    }
    return 0;
}