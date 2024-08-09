#include <iostream>
using namespace std;

class Node{
public: 
int data;
Node*left;
Node*right;

Node(int value){
    this->data = value;
    this->left = NULL;
    this->right = NULL;
}

};
// it return root node 
// create a Binary tree 
Node * CreatBTree(){
int data;
cout<<" enter your data: ";
cin>>data;
if(data ==-1){
    return NULL;
} 
// step 1 -> create root node 
Node*root = new Node(data);
cout<<root->data<<endl;

// step 2-> create left subtree
cout<<" left of node "<<root->data<<endl;
root->left = CreatBTree( );

// step 3-> create right subtree
cout<<" right of node "<<root->data<<endl;
root->right = CreatBTree( );

return root;
}

int main(){

Node* root = CreatBTree();

 return 0;
}