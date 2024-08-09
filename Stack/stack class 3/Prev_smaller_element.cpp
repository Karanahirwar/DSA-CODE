#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int>prevSmallestElement(int *arr,int size,vector<int>&prev){
stack<int>st;
st.push(-1);

//  R->L
for(int i=0;i<size;i++){
    int curr = arr[i];

   while(st.top()>=curr){
    st.pop();
   }
    
   prev[i]=st.top();

   st.push(curr);
}

return prev;

}




int main(){
int arr[5] = {4,3,10,5,6};
int size = 5;

vector<int>prev(size);

prev = prevSmallestElement(arr,size,prev);

for(int i=0 ; i<size;i++){
    cout<<prev[i]<<" ";
}

 return 0;
}