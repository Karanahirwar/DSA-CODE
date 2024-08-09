#include<iostream>
#include<stack>
using namespace std;

class Stack{
public:
int *arr;
int size;
int top1;
int top2;

Stack(int size){
    arr = new int[size];
    this->size = size;
    top1 = -1;
    top2 =size;
}

// push stack 1 
void push1(int data){
    if(top2-top1==1){
cout<<" overflow "<<endl;
    }
else {
    top1++;
    arr[top1]=data;

}

}
// stack 2 push2

void push2(int data){
if(top2-top1==1){
cout<<" overflow "<<endl;
    }

else {
      top2--;
    arr[top2]=data;
}

}

void pop1(){
if(top1==-1){
    cout<<" underflow "<<endl;
}
else{
arr[top1]= 0;
top1--;
}


}

void pop2(){

if(top2==size){
    cout<<" underflow "<<endl;
}

else{
arr[top2]= 0;
top2++;
}



}
// print stack 
void print(){
    cout<<" top1 is :"<<top1<<endl;

    cout<<" top2 is :"<<top2<<endl;
    
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }

}

};


int main(){

Stack st(5);

cout<<endl;
cout<<endl;

st.push1(1);
st.print();

st.push1(2);
st.print();

st.push1(3);
st.print();

st.push2(100);
st.print();

st.push2(200);
st.print();

// st.push2(300);
st.pop2();
st.print();

// st.pop1();





 return 0;
}