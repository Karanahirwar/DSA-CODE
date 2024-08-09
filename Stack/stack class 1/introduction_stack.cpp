#include<iostream>
#include<stack>
using namespace std;
int main(){

// creation stack
stack<int>st;

// insert data in stack
st.push(10);
st.push(20);
st.push(30);
st.push(40);
 
 // cheack size of stack
cout<<" size of stack  "<<st.size()<<endl;


// remove data in stack 
st.pop();
st.pop();
st.pop();


// cheack empty of stack
if(st.empty()){
    cout<<"stack is empty";
}
else {
    cout<<"stack is non empty ";
}

cout<<endl;
//  cheack top element in stack
cout<<" top element of stack "<<st.top()<<endl;
 return 0;

}