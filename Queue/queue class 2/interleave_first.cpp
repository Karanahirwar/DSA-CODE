#include<iostream>
#include<queue>
using namespace std;

 void InterleaveFirst_second(queue<int>&first){
int size = first.size();
queue<int>second;

for(int i= 0;i<size/2;i++){
    int temp = first.front();
    first.pop();
     
     second.push(temp);
}


for(int i = 0;i<size/2;i++){
   int temp2 = second.front();
    second.pop();
    first.push(temp2);

 temp2 = first.front();
     first.pop();
    first.push(temp2);


}


 }


int main(){
queue<int>q;
// 3 7 5 6 8 9
q.push(3);
q.push(7);
q.push(5);
q.push(6);
q.push(8);
q.push(9);


InterleaveFirst_second(q);

cout<<"printing ans queue "<<endl; 
while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
}


 return 0;
}