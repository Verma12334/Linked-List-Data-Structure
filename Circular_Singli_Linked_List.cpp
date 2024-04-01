#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    // constructor
    node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertnode(node *&tail, int elt, int d) {
    // assuming that the element is present in the list

    // empty list
    if (tail == NULL) {
        node *newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else{
    // non-empty list
    node *curr = tail;
    while (curr->data != elt) {
        curr = curr->next;
    }
    node *temp = new node(d);
    temp->next = curr->next;
    curr->next = temp;
}
} 

void deletenode(node*&tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"List is empty, please check again "<<endl;
    }
    else{
        //non empty
        //assuming that "value"is present int the linked list
        node*prev=tail;
        node*curr=prev->next;

        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }

}

void print(node*tail) {
    node *temp = tail;
      if(tail==NULL){
        cout<<"List is empty, please check again "<<endl;
        return;
    }
    do {
        cout << tail->data << " ";
         tail = tail->next;
    } while ( tail != temp);
    cout << endl;
}

int main() {
    node *tail = NULL;
    insertnode(tail, 5, 3);
    print(tail);
    insertnode(tail, 3, 5);
    print(tail);
    insertnode(tail, 5, 7);
    print(tail);
    insertnode(tail, 7, 9);
    print(tail);
    insertnode(tail, 9, 15);
    print(tail);
    insertnode(tail, 9, 80);
    print(tail);
    insertnode(tail, 30, 10);
    print(tail);
    deletenode(tail,7);
    print(tail);
    return 0;
}
