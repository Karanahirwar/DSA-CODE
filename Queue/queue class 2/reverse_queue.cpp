#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void reverseQueue(queue<int> &q){
stack<int>s;
while(!q.empty()){
    int Frontelement = q.front();
    q.pop();

s.push(Frontelement);

}

while(!s.empty()){
int element = s.top();
s.pop();

q.push(element); 
}
// 
}


int main(){
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);



reverseQueue(q);
// printing queue 
while(!q.empty()){
cout<<q.front()<<" ";
q.pop();
}

 return 0;
}