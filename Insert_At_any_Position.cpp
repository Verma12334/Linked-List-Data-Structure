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
    //distructor
    ~node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }

};

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

void InsertAtPosition(node*&tail,node*&head,int position,int d){
     node*temp=head;
     // insert at Start
     if(position ==1){
        InserAtHead(head,d);
        return;
     }
// void InsertAtPosition(node*&head,int position,int d){
//      node*temp=head;
//      if(position ==1){
//         node*t=new node(d);
//         t->next=temp;
//         head=t;
//         return;
//      }
     int cnt=1;
     while(cnt<position-1){
        temp=temp->next;
        cnt++;
     }

     //inserting at Last Position
     if(temp->next==NULL){
        InsertAtTail(tail,d);
        return;
     }

     //creating new node
     node*nodeToInsert=new node(d);
     nodeToInsert->next=temp->next;
     temp->next=nodeToInsert;
}

void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deletrNode(node*&head,int position){
    //deleting first or start Node
    if(position==1){
        node*temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else{
        // delete any middle node or last node
        node*curr=head;
        node*prev=NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}












int main(){
    node*node1=new node(10);

    node*head=node1;
    node*tail=node1;

    print(head);

    InserAtHead(head,12);
    print(head);
  


    InsertAtTail(tail,30);
    print(head);

    InsertAtPosition(tail,head,3,50);
    print(head);

    InsertAtPosition(tail,head,5,110);
    print(head);

    InsertAtPosition(tail,head,1,1);
    print(head);

    deletrNode(head,3);
    print(head);
}