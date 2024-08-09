#include<iostream>
#include<queue>
using namespace std;

int main(){
    // max heap 
// priority_queue<int>pq;
// // insert element 
// pq.push(10);
// pq.push(20);
// pq.push(30);
// pq.push(40);

// cout<<" top element is "<<pq.top()<<endl;
// cout<<"  size  is "<<pq.size()<<endl;
// pq.pop();
// cout<<" top element is "<<pq.top()<<endl;

// if(pq.empty()){
//     cout<<" true";
// }
// else{
//     cout<<" false";
// }

priority_queue<int,vector<int>,greater<int> >pq;

cout<<" Min heap "<<endl;
// insert element 
pq.push(10);
pq.push(20);
pq.push(30);
pq.push(40);

cout<<" top element is "<<pq.top()<<endl;
cout<<" size is "<<pq.size()<<endl;
pq.pop();
cout<<" top element is "<<pq.top()<<endl;

if(pq.empty()){
    cout<<" true";
}
else{
    cout<<" false";
}



    return 0;
}