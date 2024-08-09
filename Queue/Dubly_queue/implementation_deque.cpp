#include<iostream>
#include<deque>
using namespace std;

class Deque{
public:
int *arr;
int size;
int rear;
int front;

Deque(int size){
    arr = new int[size];
   this->size = size;
 rear =-1;
 front = -1;

}

// push_back
void pushBack(int data){
// check overflow 
// check empty 
// normal case 
   
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

// push_front
void pushFront(int data){
// check overflow 
// check empty 
// normal case 

if ((rear==size-1 && front==0) ||  (rear == front -1)){
    cout<<" queue is overflow"<<endl;
}
// starting me ek bhi  element nhi h tb
else if(rear==-1 && front ==-1){
rear++;
front++;
arr[front]=data;
}

else if(front==0 && rear!=size-1){
   front = size-1;
    arr[front] = data;
   
}


else{

front--;
arr[front]=data;

}

}

void popFront(){

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

void popBack(){
   // when queue is  empty
if(rear==-1&&front==-1){
    cout<<"  queue underflow "<<endl;
}
// single element h -> empty kr do
else if(rear==front){
    arr[rear]=-1;
front= -1;
rear= -1;
}

else if(rear ==0){
    arr[rear]=-1;
    rear = size-1;
}


// single element nhi h tb 
else{
arr[rear]=-1;
rear--;

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
    Deque de(5);
    de.pushBack(10);
    de.print();
    de.pushBack(20);
    de.print();
    de.pushBack(30);
    de.print();


de.pushFront(40);
    de.print();
de.pushFront(50);
    de.print();


cout<<" rear of deque "<<de.getrear()<<endl;
cout<<" front of deque "<<de.getfront()<<endl;





return 0;
}