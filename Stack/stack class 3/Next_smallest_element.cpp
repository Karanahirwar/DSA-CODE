#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int>NextSmallestElement(int *arr,int size,vector<int>&next){
stack<int>st;
st.push(-1);

//  R->L
for(int i = size-1;i>=0;i--){
    int curr = arr[i];

   while(st.top()>=curr){
    st.pop();
   }
    
   next[i]=st.top();

   st.push(curr);
}

return next;

}




int main(){
int arr[5] = {4,3,10,5,6};
int size = 5;

vector<int>next(size);

next = NextSmallestElement(arr,size,next);

for(int i=0 ; i<size;i++){
    cout<<next[i]<<" ";
}

 return 0;
}