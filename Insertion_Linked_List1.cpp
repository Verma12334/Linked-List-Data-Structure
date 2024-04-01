#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    //constructor
    node(int a){
        this->data=a;
        this->next=NULL;
    }
};

void InsertAtPosition(node*&head,int position,int d){
     node*temp=head;
     int cnt=1;
     while(cnt<position-1){
        temp=temp->next;
        cnt++;
     }

     //creating new node
     node*nodeToInsert=new node(d);
     nodeToInsert->next=temp->next;
     temp->next=nodeToInsert;
}


void InsertAtTail(node*&tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}

void InserAtHead(node*&head,int d){
    //new node create
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}

void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    //create a new node
    node*node1=new node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    //head pointed to
    node*head=node1;
    node*tail=node1;
    // InserAtHead(head,12);
    // InserAtHead(head,15);
    // InserAtHead(head,18);
    // InserAtHead(head,67);
    // InserAtHead(head,89);
    // InserAtHead(head,89);
    // InserAtHead(head,90);
    // InserAtHead(head,443);


InsertAtTail(tail,89);
InsertAtTail(tail,899);
InsertAtTail(tail,897);
InsertAtTail(tail,895);
InsertAtTail(tail,899);
InsertAtTail(tail,890);
    print(head);
}