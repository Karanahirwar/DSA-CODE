#include<iostream>
#include<queue>
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

Node* InsertIntoBst(Node*root,int data){
	// if no node is exits 
    if(root==NULL){
        root = new Node(data);
        return root;
    }

// its not a first node  
    if(root->data< data){
      root->right=  InsertIntoBst(root->right,data);
    }
    else{
    root->left= InsertIntoBst(root->left,data);

    }
    return root;

}



// create a Binary tree 
void  CreatBST(Node* &root){
int data;
cout<<" enter your data: ";
cin>>data;
while (data !=-1){
  cout<<" enter your data:";
  root = InsertIntoBst(root,data);
  cin>>data;

} 


}

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

 void StorInorderTraversal(Node*root,vector<int>&inorder){
    if(root==NULL){
        return ;
    }
    // inordertraversal 
    // LNR
    // L
StorInorderTraversal(root->left,inorder);

// N 
inorder.push_back(root->data);
// R
StorInorderTraversal(root->right,inorder);


}

void replaceUsingPostorder(Node*root,vector<int>inorder,int &Index){
if(root==NULL){
    return;
}
// LRN postorder 
// L
replaceUsingPostorder(root->left,inorder,Index);

//R
replaceUsingPostorder(root->right,inorder,Index);

// N
root->data = inorder[Index];
Index++;

}





Node*ConvertBSTintoMaxHeap(Node *root){
    vector<int>inorder;
// store Inorder traversal 
StorInorderTraversal(root,inorder);
// replace the inorder value stored value with the post order traversal
int Index =0;

replaceUsingPostorder(root,inorder,Index);
return root;
}







int main(){
    Node*root = NULL;
 	CreatBST(root);



cout<<"printing levelorder  traversal"<<endl;
levelOrderTraversal(root);

cout<<endl;
cout<<" printing Heap "<<endl;

ConvertBSTintoMaxHeap(root);
levelOrderTraversal(root);
  return 0;

}