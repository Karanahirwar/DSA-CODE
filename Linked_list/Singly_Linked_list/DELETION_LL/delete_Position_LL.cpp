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

void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty linked list (head and tail both are null)
        // step 1  -> creat new node
        Node *newnode = new Node(data);
        // step 2 update head and tail
        head = newnode;
        tail = newnode;
    }
    else
    {
        // not empty linked list
        // step 1  -> creat new node
        Node *newnode = new Node(data);
        // step 2 -> attach newnode to head node
        newnode->next = head;
        // step 3-> update date

        head = newnode;
    }
}

// InsertAttail

void InsertAttail(Node *&head, Node *&tail, int data)
{
    Node *temp = head;
    if (head == NULL)
    {
        // empty linked list (head and tail both are null)
        // step 1  -> creat new node
        Node *newnode = new Node(data);
        // step 2 update head and tail
        head = newnode;
        tail = newnode;
    }
    else
    {
        // not empty linked list
        // step 1  -> creat new node
        Node *newnode = new Node(data);
        // step 2 -> attach newnode to tail node
        tail->next = newnode;
        // step 3-> update date
        tail = newnode;
    }
}

void InsertAtPostion(Node *&head, Node *&tail, int position, int data)
{
    int length = printlength(head);
    // case 1-> start me insert
    if (position == 1)
    {
        InsertAtHead(head, tail, data);
    }

    // case 2-> last me insert
    else if (position == length + 1)
    {
        InsertAttail(head, tail, data);
    }
    // case 3 -> middle me  insert
    else
    {
        // step->1
        // creat new node
        Node *newnode = new Node(data);
        // travers prev and curr to position
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
 
        // step->2
        // attach prev ka next,newnode se
        prev->next = newnode;
        // step->3
        // attach newnode ka next,curr se

        newnode->next = curr;
    }
}

 void DeleltAtposition(Node*&head,Node*&tail,int position){
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
 else if(position==1){
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
else if(position==length){

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
else{

// step 1-> creat   prev and curr pointer 
Node*prev=NULL;
Node*curr=head;

while(position != 1){
    position--;
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
// experiment 
 void DeleltAtDATA(Node*&head,Node*&tail,int data){
    int length = printlength(head);
    
    // if LL is empty
if(head==NULL){
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

    Node *head = NULL;
    Node *tail = NULL;

    InsertAttail(head, tail, 200);
    InsertAttail(head, tail, 300);
    InsertAtHead(head, tail, 100);
    InsertAttail(head, tail, 400);
    InsertAttail(head, tail, 500);

    //     // statical object creation
    // // Node n;

    // // Dynamic object creation

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fiveth = new Node(50);
    // Node *tail = fiveth;

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fiveth;

    // // linked list creat ho chuki h
    // Node*head=first;

    printLL(head);

    // InsertAtHead(head, tail,500);
    // printLL(head);

    // int length = printlength(head);

    // InsertAtPostion(head, tail, 3, 3000);


    // DeleltAtposition(head,tail,3);
    DeleltAtDATA(head,tail,300);

    printLL(head);

    return 0;
}