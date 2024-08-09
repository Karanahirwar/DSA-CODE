#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int>&q){
// base case 
if(q.empty()){
    return;
}

// ek case hm solve krege 
int element = q.front();
q.pop();

// recersive call 
reverseQueue(q);
cout<<element<<endl;
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

return 0;

}