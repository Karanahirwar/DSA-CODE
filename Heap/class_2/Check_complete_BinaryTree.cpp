#include<iostream> 
using namespace std;

class Info{
    int MaxValue;
    bool isHeap;
// constructor 

Info (int a,bool b){
    this->MaxValue = a;
    this->isHeap =b;
}

};


Info checkHeap(Node* root ){
if(root==NULL){
    Info temp;
    temp.MaxValue = INT_MIN;
    temp.isHeap = true;
    return temp;
}
if(root->left ==NULL && root->right ==NULL){
    Info temp;
    temp.MaxValue = root->data;
    temp.isHeap = true;
     return temp;
}
 Info leftans = checkHeap(root->left);
 Info Rightans = checkHeap(root->right);
 // 1 case mujhe solve krna h 
 if(root->data >leftans.MaxValue && root->data > rightans.MaxValue && 
 leftans.isHeap && Rightans.isHeap){
Info ans;
  ans.MaxValue = root->data;
  ans.isHeap = true;
 }
 else{
    Info ans;
    ans.MaxValue= max(root->data,max(leftans.MaxValue,Rightans.Maxvalue))
   ans.isHeap = false; 
   return ans;
 }
 

}


int main(){
Info f(100,true);
f.checkHeap(40);
f.checkHeap(50);
f.checkHeap(10);

cout<<checkHeap()<<endl;

    return 0;
}