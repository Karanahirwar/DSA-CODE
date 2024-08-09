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

void printLL(Node* &head){
// function me kabhi bhi original pointer ka use mt krna 
Node*temp = head; 
// temp name ka pointer jo head ke equal h 
while(temp !=NULL){
    cout<<temp->data<<"->";
 temp = temp->next;
}
cout<<endl;
}



// InsertAttail

void InsertAttail(Node*&head,Node*&tail,int data){
    Node*temp=head;
   if(head==NULL){
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
        // step 2 -> attach newnode to tail node 
        tail->next = newnode;
        // step 3-> update data
     tail = newnode;
    }

}

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
Node*tail = fiveth;
printLL(head);

InsertAttail(head,tail,100);
printLL(head);
 
 return 0;
}