#include<iostream>
#include<stack>
using namespace std;

  void  InsertAtSorted(stack<int> &St,int &Element){
        // base case 
        if(St.empty() || Element >St.top()){
     St.push(Element);
      return;
        }    
        // ek case hm solve krege
        int temp = St.top();
        St.pop();
        
        // baki recursion sambhal lega 
       InsertAtSorted(St,Element); 
        
        //back tracking 
        St.push(temp);
     
    }
  void  ShortStack(stack<int> &St){
        // base case 
        if(St.empty() ){
            cout<<" stack is empty can't shorted";
      return;
        }    
        // ek case hm solve krege
        int temp = St.top();
        St.pop();
        
        // baki recursion sambhal lega 
       ShortStack(St); 
        
        //back tracking 
        InsertAtSorted(St,temp);
     
    }


int main(){
stack<int>St;
St.push(10);
St.push(7);
St.push(12);
St.push(15);
St.push(101);
// int Element = 25;
//  InsertAtSorted(St,Element);

ShortStack(St);

while(!St.empty()){
    cout<<St.top()<<" ";
    St.pop();
}

 return 0;
}