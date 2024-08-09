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
    cout<<"I  am a parametrized ctor"<<endl;
    this->data=data;
    this->next=NULL;
}


};

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


cout<<" length is "<<printlength(head)<<endl;


 return 0;
}