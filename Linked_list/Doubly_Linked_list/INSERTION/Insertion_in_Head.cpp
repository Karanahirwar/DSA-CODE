#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next; // next ek pointer h heap me 
Node *prev;

//  defualt constructor
Node(){
    cout<<" i am a default ctor";
//    this keyword is show current object 
    this->next=NULL;
    this->prev=NULL;
}

// parametrized constructor
Node(int data){
    // cout<<"I  am a parametrized ctor"<<endl;
    this->data=data;
    this->next=NULL;
    this->prev = NULL;
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

int printlength(Node* head){
//  kbhi bhi ll me original pointer se chedchhad na kre 
Node*temp = head;
int length=0;
while(temp != NULL){
    length++;
    temp=temp->next;
}
return length;

}

void InsertAtHead(Node* &head,Node* &tail, int data){
if(head ==NULL){
    // LL is empty
 // step 1 -> creat new node
Node*newNode = new Node(data); 
 // step 2 -> creat new node
head = newNode;
tail = newNode;

}
else {
    // LL is not empty 
     // step 1 -> creat new node
Node*newNode = new Node(data);

// step 2 -> link head se 
newNode->next = head;
head->prev = newNode;
// step 2-> update kr do 
head = newNode;
}

}

int main(){

Node*head =NULL;
Node*tail =NULL;

InsertAtHead(head,tail,50);
InsertAtHead(head,tail,40);
InsertAtHead(head,tail,30);
InsertAtHead(head,tail,20);
InsertAtHead(head,tail,10);

printLL(head);
return 0;
}