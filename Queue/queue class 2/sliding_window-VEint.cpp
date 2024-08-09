#include<iostream>
#include<deque>
using namespace std;

void Printfirstnegative(int *arr,int size,int k){

deque<int>dq;
// process  first k element -> first window 
for(int index = 0;index<k;index++){
    int element = arr[index];

if(element<0){
    dq.push_back(index);
}
}
// process remaining window -> removal and addition 

for(int index = k; index<size; index++){
// aage bdne se phle purani window ka anser nikal do 

if(dq.empty())
{
cout<<" 0";
}
else{
    cout<<arr[dq.front()]<<" ";
}

//removal -> jo bhi index out of range h, usko queue se delete kr do 
if(index-dq.front()>=k){
dq.pop_front();
} 
   
// addition -> negative value ko 
if(arr[index]<0){
    dq.push_back(index);
}

}
// last window ka answer 

if(dq.empty())
{
cout<<" 0";
}
else{
    cout<<arr[dq.front()]<<" ";
}

}
int main(){
int arr[]={2,-5,4,-1,-2,0,5};   


int k = 3;
int size =  7;

Printfirstnegative(arr,size,k);
 return 0;
}