#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;


//  defualt constructor
Node(){
    cout<<" i am a default ctor";
//    this keyword is show current object 
    this->next=NULL;
}

// parametrized constructor
Node(int data){
    // cout<<"I  am a parametrized ctor"<<endl;
    this->data=data;
    this->next=NULL;
}


};

void printAllLinkedlist(Node* head){
//  kbhi bhi ll me original pointer se chedchhad na kre 
Node*temp = head;

while(temp != NULL){
  cout<<temp->data<<"->";
  temp = temp->next;
}
return;

}

 Node* reverseLL( Node* head){

 Node* prev = NULL;
  Node* curr = head;

while(curr->next !=NULL){
    Node*nextnode = curr->next;
    curr ->next = prev;
    prev = curr;
  curr = nextnode;
}
return prev;

 }

// Node* addNumINLL(node*&h)


int main(){
    // statical object creation 
// Node n;

// Dynamic object creation 

Node* first = new Node(10);
Node* second = new Node(20);
Node* third = new Node(30);
Node* fourth = new Node(40);
Node* fiveth = new Node(50);

first->next = second;
second->next = third;
third->next = fourth;
fourth->next = fiveth;


// linked list creat ho chuki h 
Node*head=first;


printAllLinkedlist(head);
cout<<endl;
cout<<reverseLL(head);
printAllLinkedlist(head);


 return 0;
}