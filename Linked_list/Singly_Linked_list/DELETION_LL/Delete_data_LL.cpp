#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // next ek pointer h heap me

    //  defualt constructor
    Node()
    {
        cout << " i am a default ctor";
        //    this keyword is show current object
        this->next = NULL;
    }

    // parametrized constructor
    Node(int data)
    {
        // cout<<"I  am a parametrized ctor"<<endl;
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"dtor is called -> "<<this->data<<endl;
    }
};

void printLL(Node *head)
{
    // function me kabhi bhi original pointer ka use mt krna
    Node *temp = head;
    // temp name ka pointer jo head ke equal h
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int printlength(Node *head)
{

    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
// experiment 
 void DeleltAtposition(Node*&head,Node*&tail,int data){
    int length = printlength(head);
    
if(head==NULL){
    // if LL is empty
    cout<<"cannot delete because LL is empty";
    return;
}

// jb LL me single element ho 
if(head==tail)
{
    Node*temp=head;
    head=NULL;
    tail=NULL;
    
}



// Delete at head
 else if(data==head->data){
    // step 1-> creat pointer temp 
    Node*temp=head;
// step 2-> head ko aage bda do 
head = temp->next;
//step 3-> 
temp->next = NULL;
// step 4-> delete temp 
delete temp; 


}
// Delete at tail
else if(data==tail->data){

    // step 1-> creat pointer prev jo tail ke just peeche point krega 
Node*prev=head;
while(prev->next !=tail){
    prev= prev->next;
}

// step 2-> prev pointer  ko null kr do  
  prev->next = NULL;
// step 3-> delete temp 
delete tail; 
//step 4->  update tail
tail = prev;
}

// delete At position 
else{

// step 1-> creat   prev and curr pointer 
Node*prev=NULL;
Node*curr=head;

while(curr->data != data){
    prev = curr;
    curr = curr->next;
}

// step 2-> prev  ke next ko connect kr do 
prev->next = curr->next;

// step 3-> curr node ko isolate kro (alg kro)
curr->next = NULL;

// step 4->  delete kr do curr ko 
delete curr;
}

 }

int main()
{
    // statical object creation
    // Node n;

    // Dynamic object creation

    Node* first = new Node(100);
    Node* second = new Node(200);
    Node* third = new Node(300);
    Node* fourth = new Node(400);
    Node* fiveth = new Node(500);
    Node *tail = fiveth;

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fiveth;

    // linked list creat ho chuki h
    Node*head=first;
   

  printLL(head);

   DeleltAtposition(head,tail,300);
    printLL(head);

    return 0;
}