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

void InsertAtTail(Node* &head,Node* &tail, int data){
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

// step 2 -> link  
tail->next = newNode;
newNode->prev = tail;
// step 2-> update kr do 
tail = newNode;
}

}
void InsertAtMiddle(Node* &head,Node* &tail,int position, int data){
int length = printlength(head);

if(head ==NULL){
    // LL is empty
 // step 1 -> creat new node
Node*newNode = new Node(data); 
 // step 2 -> creat new node
head = newNode;
tail = newNode;
}

else if(position==1){
InsertAtHead(head,tail,data);
    
}
else if(position==length+1){
InsertAtTail(head,tail,data);

}

else {
    // step->1
        // creat new node
        Node *newnode = new Node(data);
     // step 2-> travers prev and curr to position
        Node *prevNode = NULL;
        Node *currNode = head;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
 
        // step->3 link node 
     prevNode->next = newnode;
     newnode ->prev = prevNode;
    //  step ->4 link node 
    currNode->prev = newnode;
       newnode->next = currNode;
}

}



int main(){

Node*head =NULL;
Node*tail =NULL;

InsertAtHead(head,tail,30);
InsertAtHead(head,tail,20);
InsertAtHead(head,tail,10);
InsertAtTail(head,tail,40);
InsertAtTail(head,tail,50);
InsertAtTail(head,tail,60);
printLL(head);


InsertAtMiddle(head,tail,3,25);
printLL(head);
return 0;
}