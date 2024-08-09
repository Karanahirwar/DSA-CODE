#include <iostream>
using namespace std;


void Heapify(int *arr,int n , int Index){
      int leftIndex = 2*Index;
        int rightIndex = 2*Index + 1;
             int largestIndex = Index;

// check left child me 
        if(leftIndex <= n && arr[largestIndex]< arr[leftIndex] ){
         largestIndex  = leftIndex;
    }
    // check right child 
    if(rightIndex <= n && arr[largestIndex]< arr[rightIndex] ){
         largestIndex  = rightIndex;
    }
    if(largestIndex != Index)      {
        swap( arr[largestIndex],arr[Index]);

      Index = largestIndex;
    Heapify(arr,n,Index);
    }

}

void BuildHeap(int arr[],int n){
    // n/2 +1 se n tk leaf node hota h vo apne aap heapify hota h 
    // that why apne loop n/2 se 1 tk chalaya h
  for(int index = n/2;index>0; index--){
    Heapify(arr,n,index);
  }
}

void heapsort(int arr[],int n){
    while(n!=1){
        // here n-1 tk nhi aayega kyuki 1 index se start kr rhe h 
    swap(arr[1],arr[n]);
    n--;
 Heapify(arr,n,1);
    }
}

int main(){

  int arr[] = {-1,25,50,15,5,10,12};
  int n = 6;
BuildHeap(arr,n);
cout<<" bulding heap : "<<endl;
for(int i =1;i<=n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;

cout<<"  heapsorting printing Heap "<<endl;
heapsort(arr,n);
for(int i =1;i<=n;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}
