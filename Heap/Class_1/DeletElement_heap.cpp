#include <iostream>
using namespace std;

class Heap {
public:
int * arr;
int size;
int capacity;

Heap(int capacity){
    this->arr = new int[capacity];
    this->size = 0;
    this->capacity = capacity;
}


void insertElement(int value){
    if(size == capacity){
        cout<<" heap overFlow "<<endl;
    }
    // jb new element insert krege to obvisly 
    size++;
    // element insert kr do
    int index = size;

  arr[index]= value;


    // take the value of its  correct position 
  while(index>1){
        int parentIndex = index/2;
        if(arr[parentIndex]<arr[index]){
            swap(arr[parentIndex],arr[index]);
            // index ne parents index ki jagah le li h 
            index = parentIndex;

        }
        else{
            break;
        }
    }
}
// printing heap 
void printHeap( ){
    for(int i =1; i<=size;i++){
        cout<<arr[i]<<" ";
    }
}

int deleteFromHeap(){
    int answer = arr[1];
    // replacement
    arr[1] = arr[size];
    // last element ko delete uski original position se 
    // jb delete krege ho size km hoga 
    size--;
    int Index =1;
    while(Index < size){
        int leftIndex = 2*Index;
        int rightIndex = 2*Index + 1;
        // find out krege ki sabse bda kon h 

        int largestIndex = Index;   
        // check left child   

    if(leftIndex < size && arr[largestIndex]< arr[leftIndex] ){
         largestIndex  = leftIndex;
    }
    // check right child 
    if(rightIndex < size && arr[largestIndex]< arr[rightIndex] ){
         largestIndex  = rightIndex;
    }

     if(largestIndex = Index){
        break;
     }
     else{
        swap(arr[Index],arr[largestIndex]);
        Index = largestIndex;
     }

    }
    return answer;
}

};




int main(){
Heap h(20);

h.insertElement(10);
h.insertElement(20);
h.insertElement(5);
h.insertElement(11);
h.insertElement(6);

cout<<"printing the content of heap: "<<endl;
h.printHeap( );

cout<<endl;
cout<<" delete Element in heap :";
int ans = h.deleteFromHeap();
cout<<  ans<<endl;

cout<<"printing the content of heap: "<<endl;
h.printHeap( );



    return 0;
}
