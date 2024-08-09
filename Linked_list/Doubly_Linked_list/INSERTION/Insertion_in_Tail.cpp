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


int main(){
Node*head =NULL;
Node*tail =NULL;

InsertAtTail(head,tail,10);
InsertAtTail(head,tail,20);
InsertAtTail(head,tail,30);
InsertAtTail(head,tail,40);

printLL(head);
cout<<"insert newNode at tail"<<endl;
cout<<endl;
InsertAtTail(head,tail,50);
InsertAtTail(head,tail,60);
printLL(head);

return 0;
}