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

Node* ConvertDLLtoBST (Node* &head,int n){
    if(head==NULL || n<=0){
        return NULL;
    }
    
    // LNR 
    // L 
    Node* leftSubtree = ConvertDLLtoBST(head,n/2);

    // N
    // root is denote current node 
   Node* root = head;
   root->left = leftSubtree;
   head = head->right;

   // R 
    Node* rightsubtree = ConvertDLLtoBST(head,n-n/2-1);
    root->right = rightsubtree;

    
    
}


int main(){
  
Node*first = new Node(10);
Node*second = new Node(20);
Node*third = new Node(30);
Node*fourth = new Node(40);
Node*fivth = new Node(50);
Node*sixth = new Node(60);
Node*seventh = new Node(70);

first->right = second;
second->left = first;
second->right= third;
third->left = second;
third->right = fourth;
fourth->left = third;
fourth->right = fivth;
fivth->left = fourth;
fivth->right = sixth;
sixth->left = fivth;
sixth->right = seventh;
seventh->left = sixth;
seventh->right = NULL;
Node*head = first;

Node *root = ConvertDLLtoBST(head,7);

levelOrderTraversal(root);

}
