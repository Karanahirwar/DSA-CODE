#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&st,int &pos,int &ans){
    // base case 
    if(pos==1){
// if middle element delete krna ho to 
// st.pop();
// cout<<" delete element"<<st.top()<<endl;
// st.pop();

     ans = st.top();
     return;
    }

// ek case hm solve krege 
    pos--;
    int temp = st.top();
    st.pop();
    
    // baki recursion handle kr lega 

 solve(st,pos,ans);

// backtracking 

st.push(temp);

    
}

 int  getMidddleElement(stack<int>&st,int &size){
    // yha postion find krege phle 

if(st.empty()){
    // stack empty
    cout<<"stack is empty, not have middle element  "<<endl;
    return -1;
}
else{
    // stack is not empty 
    // odd size 
    int pos =0;
    if(size &1==1){
        pos = (size/2)+1;

    }
    // even size 
    else{
        pos = size/2;
    }
    
    int ans  = -1;
    solve(st,pos,ans);
    return ans;
    
}
 }


int main(){

stack<int>st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
st.push(60);
st.push(70);
st.push(80);
// cout<<"before deleting element "<<endl;
int size = st.size();
cout<<"size is "<<st.size()<<endl;

int mid =  getMidddleElement(st,size);
// cout<<"after deleteing element:"<<endl;

// cout<<"size is "<<st.size()<<endl;


cout<<"middle element is:" <<mid<<endl;

 return 0;
}