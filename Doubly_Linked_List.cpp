#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*prev;
    node*next;
    //constructor
    node(int a){
        this->data=a; 
        this->next=NULL;
        this->prev=NULL;
    }
};

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlenght(node*head){
     node*temp=head;
     int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
   return len;
}

void InsertAtHead(node*&head,int d){
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp->next;
    head=temp;
}
int main(){
    node*node1=new node(10);
    node*head=node1;
    print(head);
    cout<<"Lenght of linled list is:="<<getlenght(head)<<endl;
    InsertAtHead(head,12);
     print(head);
    InsertAtHead(head,14);
     print(head);
    InsertAtHead(head,16);
     print(head);
    InsertAtHead(head,18);
     print(head);
    InsertAtHead(head,20);
     print(head);
    InsertAtHead(head,22);
     print(head); 
}