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
void InsdertAtTail(node*&tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    temp->prev=tail->next;
    tail=temp;
}

void InsertAtPosition(node*&tail,node*&head,int poistion,int d){
    //insert at start
    if(poistion==1){
        InsertAtHead(head,d);
        return;
    }
    // insert orther then frist position
    node*temp=head;
    int cnt=1;
    while(cnt<poistion-1){
       temp=temp->next;
        cnt++;
    }

    //inserting at last poistion
    if(temp->next==NULL){
        InsdertAtTail(tail,d);
        return;
    }

    //creating a node for d
     node*nodeToInsert=new node(d);
     nodeToInsert->next=temp->next;
     temp->next->prev=nodeToInsert;
     temp->next=nodeToInsert;
     nodeToInsert->prev=temp;
}


int main(){
    node*node1=new node(10);
    node*head=node1;
    node*tail=node1;
    print(head);
    cout<<"Lenght of linled list is:="<<getlenght(head)<<endl;
    InsertAtHead(head,12);
    print(head);
    InsdertAtTail(tail,12);
    print(head);
    InsdertAtTail(tail,14);
    print(head);
    InsertAtPosition(tail,head,2,13);
    print(head);
    InsertAtPosition(tail,head,1,9);
    print(head);
    InsertAtPosition(tail,head,7,100);
    print(head);
} 