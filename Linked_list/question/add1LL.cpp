#include<iostream>
using namespace std;


class Node{
public:
int data;
Node*next;

Node(){
    // cout<<" this is default constructor:";
    // this point to current object 
    this->next = NULL;

}
Node( int data){
    // cout<<" this is parametrized  constructor:";
    // this point to current object 
    this->next = NULL;
    this->data = data;

}


};

void  printLL( Node* &head){
Node *temp = head;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;

}


}

Node* reverseLL(Node* &head){

Node *prev = NULL; 
Node *curr = head ;
while(curr != NULL){
Node*newnode = curr->next;
curr->next = prev;
prev = curr;
curr = newnode;
} 

return prev;

}


void ADDoneLL(Node* & head){
    // reverse 

 head = reverseLL(head);
    // add 1 
    int carry = 0;
    Node * temp = head;
 while(temp->next!=NULL){
int totalsum = temp->data +carry;
    int digit = totalsum %10;
   carry = totalsum /10;

  temp->data =  digit;
   temp = temp->next;

if(carry ==0){
    break;
}

 }
 // last node me ruk chuke h 
 // last node me process 

if(carry!=0){
    int totalsum = temp->data +carry;
    int digit = totalsum %10;
   carry = totalsum /10;
   temp->data = digit;
}

if(carry!=0){
    Node*newnode = new Node(carry);

    temp->next = newnode; 
}

    // reverse again 

 head = reverseLL(head);

}



int main(){

// Node n(101); // create  static object 

Node *first = new Node(1);
Node *second = new Node(2);
Node *third = new Node(3);
Node *fourth = new Node(4);

Node* head = first;
first->next = second;
second->next = third;
 third->next = fourth;
// fourth->next = NULL;


printLL(head);
cout<<endl;


// Node* ans =reverseLL (head);
// printLL(ans);

ADDoneLL(head);

cout<<endl;
printLL(head);

 return 0;
}