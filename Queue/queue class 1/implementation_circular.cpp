#include<iostream>
#include<queue>
using namespace std;

// implementation of circular queue 
class Queue{
public:
int *arr;
int size;
int rear;
int front;
// constructor 

Queue(int size){
    this->size = size;
    // dynamic array
    arr = new int(size);

front = -1;
rear = -1;
}

void push(int data){
    // check empty

if ((rear==size-1 && front==0) ||  (rear == front -1)){
    cout<<"queue is overflow "<<endl;
}

else if (rear==size-1 && front!=0) {
rear = 0;
arr[rear]= data;

}

else if(rear==-1 && front==-1) {
front++;
rear++;
arr[rear]=data;
    }

else{
    rear++;
    arr[rear] = data;
}
}

void pop(){
if(rear==-1 &&  front==-1){
    cout<<" queue is underflow :"<<endl;
}
else if (rear == front){
    arr[front]=-1;
    front =-1;
    rear = -1;
}

else if(front ==size-1){
    arr[front] = -1;
    front =0;
}

else {
    arr[front]=-1;
    front++;
}

}

int  getsize(){
if(rear==-1 && front ==-1){
return 0;
}
else{
    return rear-front+1;
}

}

int  getfront(){
if(rear==-1 && front ==-1)
{
    cout<<" front not exits";
    return -1;
}
else{
    return arr[front];
}

}

int  getrear(){
if(rear==-1)
{
    cout<<" rear not exits";
    return -1;
}
else{
    return arr[rear];
}
}

// print 
void print(){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


};





int main(){

Queue q(5);
q.push(10);
// q.print();
q.push(20);
q.print();
q.push(30);
q.print();
q.push(40);
q.print();
q.push(50);
q.print();



q.pop();
q.print();
q.pop();
q.print();
q.pop();
q.print();
q.pop();
q.print();

q.push(100);
q.print();
q.push(200);
q.print();
q.push(300);
q.print();
q.push(400);
q.print();

q.push(400);
q.print();





cout<<" front of queue"<<q.getfront()<<endl;
cout<<" rear of queue"<<q.getrear()<<endl;
cout<<" size of queue"<<q.getsize()<<endl;


 return 0;
}