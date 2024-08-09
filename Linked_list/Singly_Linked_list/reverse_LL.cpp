#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next; // next ek pointer h heap me 


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

// print all linked list
void printLL(Node* head){
// function me kabhi bhi original pointer ka use mt krna 
Node*temp = head; 
// temp name ka pointer jo head ke equal h 
while(temp !=NULL){
    cout<<temp->data<<"->";
 temp = temp->next;
}
cout<<endl;
}

// Insertion at head function 

void InsertAtHead(Node*&head,Node* &tail,int data){
    if(head==NULL){
    // if(tail==NULL){
        // empty linked list (head and tail both are null)
        // step 1  -> creat new node 
        Node* newnode = new Node(data);
        // step 2 update head and tail 
        head = newnode;
        tail = newnode;
    }
    else {
        // not empty linked list 
        // step 1  -> creat new node 
        Node* newnode = new Node(data);
        // step 2 -> attach newnode to head node 
        newnode->next = head;
        // step 3-> update head
        
     head = newnode;
    }
 }

Node* reveseLL(Node*prev,Node*curr){
// base case
if(curr ==NULL){
    return prev;
}

// ek case tum solve kro 

Node*nextnode = curr->next;
curr->next = prev;

prev = curr;
curr = nextnode;

 return reveseLL(prev,curr);

 }


int main(){
    // statical object creation 
// Node n;

// Dynamic object creation 
Node*head =NULL;
Node*tail =NULL;

InsertAtHead(head,tail,40);
InsertAtHead(head,tail,30);
InsertAtHead(head,tail,20);
InsertAtHead(head,tail,10);

printLL(head);

Node*prev = NULL;
Node*curr = head;


Node *ans = reveseLL(prev,curr);
printLL(ans);
return 0;
}

