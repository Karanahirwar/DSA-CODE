#include<iostream>
#include<queue>
using namespace std;

int KthLargestElement(int arr[],int size,int k){
priority_queue<int,vector<int>,greater<int>>pq;
for(int i =0;i<k;i++){
    int element = arr[i];
    pq.push(element);
}

for(int i = k ;i<size;i++){
    int element = arr[i];
    if(pq.top() < element){
        pq.pop();
        pq.push(element);
    }
}
int ans = pq.top();
return ans;

}

int main(){
    int arr[] = {3,8,7,6,11,2,1,5};
    int size = 8;
    int k = 3;
    int answer =KthLargestElement(arr,size,k);
    cout<<" kth smallest element "<<answer<<endl; 
    return 0;
}