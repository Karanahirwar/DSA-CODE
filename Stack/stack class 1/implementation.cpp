#include<iostream>
#include<stack>
using namespace std;

class  Stack{
public:
int size;
int top;
int *arr;
int data;
// constructor is used to initilize data 

// parametrized constructor 
Stack(int size){
this->size = size;
arr =  new int[size]; 
this->top = -1;
} 


// push 
void push(int data){
    if(top==size-1){
        cout<<" stack  is overflow"<<endl;
        return;
    }
    else {
        top++;
        arr[top]=  data;
    }
}

// pop 
void pop(){
    // cout<<" top is :"<<top<<endl;
if(top==-1){
    cout<<" stack is underflow:";
    return;
}
else {
    top--;
}

}

// empty 

bool isempty(){
    if(top==-1){
        return true;
    }
    else {
        return false;
    }
}


// size (jha tk arr me data rkha h )
int getsize(){
return top+1;
}


// top 
int gettop(){
    if(top==-1){
 cout<<" stack is empty :";
 return -1; 
    }
    return arr[top];
}



// printing stack 
void print(){
    cout<<"Top:"<<top<<endl;
    cout<<"top element:"<<gettop()<<endl;
    cout<<" stack  ";

for(int i=0; i<getsize();i++){
    cout<<arr[i]<<endl;
    
}
cout<<endl;
}
};


int main(){
// creation
Stack st(5);

// push 
st.push(10);
st.print();


cout<<"Top element:"<<st.gettop()<<endl;

cout<<" size of stack "<<st.getsize()<<endl;

cout<<"cheack empty "<<st.isempty()<<endl;



// st.push(20);
// st.print();

// cout<<" after pop operation:"<<endl;
// st.pop();
// st.print();

// st.pop();
// st.print();

// st.pop();
// st.print();




 return 0;
}
