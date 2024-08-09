#include<iostream>
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




//  PreOreder  Traversal 
void PreOrederTraversal(Node*root){
    // preorder NLR
    // base case 
    if(root ==NULL){
        return;
    }
// N 
cout<< root->data<<" ";
// L 
PreOrederTraversal(root->left);

// R
PreOrederTraversal(root->right);
}

//  InOreder  Traversal 
void InOrederTraversal(Node*root){
    // Inorder LNR
    // base case 
    if(root ==NULL){
        return;
    }
    
// L 
InOrederTraversal(root->left);
// N 
cout<< root->data<<" ";

// R
InOrederTraversal(root->right);
}


//  PostOrederTraversal 
void PostOrederTraversal(Node*root){
    // preorder NLR
    // base case 
    if(root ==NULL){
        return;
    }
// L 
PostOrederTraversal(root->left);

// R
PostOrederTraversal(root->right);

// N 
cout<< root->data<<" ";
}

int main(){
    Node*root = CreatBTree();
cout<<"printing preorder traversal"<<endl;
PreOrederTraversal(root);

cout<<endl;

cout<<"printing INorder traversal"<<endl;
InOrederTraversal(root);
cout<<endl;

cout<<"printing postorder traversal"<<endl;
PostOrederTraversal(root);

    return 0;
}