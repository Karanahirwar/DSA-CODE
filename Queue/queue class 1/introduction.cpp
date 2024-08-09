#include<iostream>
#include<queue>
using namespace std;
int main(){
queue<int>q;

// insertion 
q.push(10);
q.push(20);
q.push(30);

// cheack first element of queue
cout<<"front(first) element of queue: "<<q.front()<<endl;

// cheack last element of queue
cout<<"last(rear) element of queue: "<<q.back()<<endl;



// cheack size of queue
cout<<"size of queue:"<<q.size()<<endl;

// cheack empty
if(q.empty()){
    cout<<"queue is empty"<<endl;
}
else{
    cout<<"queue is not empty"<<endl;

}

// remove  
// q.pop();
// q.pop();

// if(q.empty()){
//     cout<<"queue is empty"<<endl;
// }
// else{
//     cout<<"queue is not empty"<<endl;

// }
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}
 return 0;
}
