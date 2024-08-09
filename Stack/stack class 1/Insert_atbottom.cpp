#include<iostream>
#include<stack>
using namespace std;

  void  InsertAtBottom(stack<int> &St,int &Element){
        // base case 
        if(St.empty()){
     St.push(Element);
      return;
        }    
        // ek case hm solve krege
        int temp = St.top();
        St.pop();
        
        // baki recursion sambhal lega 
       InsertAtBottom(St,Element); 
        
        //back tracking 
        St.push(temp);
     
    }


int main(){
stack<int>St;
St.push(10);
St.push(20);
St.push(30);
St.push(40);
St.push(50);
int Element = 100;
 InsertAtBottom(St,Element);

while(!St.empty()){
    cout<<St.top()<<endl;
    St.pop();
}

 return 0;
}