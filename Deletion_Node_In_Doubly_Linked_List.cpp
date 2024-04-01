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
    ~node(){
        int val=this->data;
        if(next=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data= "<<val<<endl;
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

void InsertAtHead(node*&tail,node*&head,int d){

    //EMPTY LIST
    if(head==NULL){
        node*temp=new node(d);
        head=temp;
        tail=temp;
        return;
    }
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp->next;
    head=temp;
}
void InsdertAtTail(node*&tail,node*&head,int d){

    //empty list
    if(tail==NULL){
        node*temp=new node(d);
        tail=temp;
        head=temp;
        return;
    }
    node*temp=new node(d);
    tail->next=temp;
    temp->prev=tail->next;
    tail=temp;
}

void InsertAtPosition(node*&tail,node*&head,int poistion,int d){
    //insert at start
    if(poistion==1){
        InsertAtHead(tail,head,d);
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
        InsdertAtTail(tail,head,d);
        return;
    }

    //creating a node for d
     node*nodeToInsert=new node(d);
     nodeToInsert->next=temp->next;
     temp->next->prev=nodeToInsert;
     temp->next=nodeToInsert;
     nodeToInsert->prev=temp;
}
void deletrNode(node*&head,int position){
    //deleting first or start Node
    if(position==1){
        node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        //memory free start node
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

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
      
        delete curr;
    }
} 

int main(){
    node*head=NULL;
    node*tail=NULL;
    print(head);
    cout<<"Lenght of linled list is:="<<getlenght(head)<<endl;
    InsertAtHead(tail,head,12);
    print(head);
    InsdertAtTail(tail,head,12);
    print(head);
    InsdertAtTail(tail,head,14);
    print(head);
    InsertAtPosition(tail,head,2,13);
    print(head);
    InsertAtPosition(tail,head,1,9);
    print(head);
    InsertAtPosition(tail,head,6,100);
    print(head);
    deletrNode(head,4);
    print(head);
} 

