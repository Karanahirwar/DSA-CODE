#include<iostream>
#include<queue>
using namespace std;

class Queue{
public:
int *arr;
int size;
int rear;
int front;

Queue(int size){
    arr = new int[size];
   this->size = size;
 rear =-1;
 front = -1;

}

// push 

void push(int data){
    // check overflow
if(rear==size-1){
    cout<<" queue is overflow"<<endl;
}
// starting me ek bhi  element nhi h tb
else if(rear==-1 && front ==-1){
rear++;
front++;
arr[rear]=data;
}

else{
rear++;
arr[rear]=data;

}

}

void pop(){
    // when queue is  empty
if(rear==-1&&front==-1){
    cout<<"  queue underflow "<<endl;
}
// single element h -> empty kr do
else if(rear==front){
    arr[front]=-1;
front= -1;
rear= -1;
}
// single element nhi h tb 
else{
arr[front]=-1;
front++;

}

}

bool empty(){
    if(rear==-1 && front==-1){
        return true;
    }
    else{
        return false;
    }
}

int getsize(){
    // bol jata hu
    if(rear==-1 && front==-1){
    // return rear-front;
    return 0;
}
else{
    return rear-front+1;
}
}

int getfront(){
    if(front==-1){
        cout<<" front element not exits"<<endl;
        return -1;
    }
    else{
        return arr[front];
    }
}

// self banaya h 
int getrear(){
    if(rear==-1){
        cout<<" last(rear) not exits: "<<endl;
    }
    else{
        return arr[rear];
    }
}


// printing queue

void print(){
cout<<"printing queue: "<<endl;
    for(int i=0;i<size;i++){
cout<<arr[i]<<endl;
    }
}


};



int main(){

Queue q(5);

q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.print();


// q.pop();
// q.print();
// q.push(60);
// q.print();

cout<<"check queue empty "<<q.empty()<<endl;

cout<<"get front of queue "<<q.getfront()<<endl;

cout<<"get size of queue "<<q.getsize()<<endl;

cout<<"get rear of queue "<<q.getrear()<<endl;

 return 0;
}