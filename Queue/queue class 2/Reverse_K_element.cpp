#include<iostream>
#include<queue>
#include<stack>
using namespace std;

 void Reverse_K_element(queue<int>&q, int k ){
 stack<int>s;

int size = q.size();

if(k>size || k==0){
    return;
}

// push first k element from queue to stack 
for(int i =0;i<k;i++){
    int element = q.front();
    q.pop();

s.push(element);
}


// push all k element from stack to queue 
while(!s.empty()){
    int topelement = s.top();
    s.pop();

q.push(topelement);

}
// push and pop n-k element 

for(int j=0;j<(size-k);j++){
    // baki bache element ko peeche lga do 
    int frontofqueue = q.front();
    q.pop();

    q.push(frontofqueue);
}


 }


int main(){

queue<int>q;

q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);
q.push(70);

int k = 8;
Reverse_K_element(q,k);

cout<<"printing ans queue "<<endl; 
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}

 return 0;
}