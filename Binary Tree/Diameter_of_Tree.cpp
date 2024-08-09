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
// dynamic object creation
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

int  levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
 int  count =1;
	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
                count++;
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
    return count;
}
 
    int diameterOfBinaryTree(Node* root) {
    // int  height = levelOrderTraversal( root);
        if(root==NULL){
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = levelOrderTraversal(root->left)+levelOrderTraversal(root->right);
        
        int Diameter = max(option1,max(option2,option3));
        return Diameter;
    }



int main(){
    Node*root = CreatBTree();

     int height = levelOrderTraversal(root);
    cout<<" height is "<< height<< endl;

int diameter = diameterOfBinaryTree(root);
// cout<<" diameter is "<< diameter<< endl;
    return 0;
} 