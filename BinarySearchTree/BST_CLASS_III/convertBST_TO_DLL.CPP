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

Node* BSTfromInorder(int inorder[],int start,int end )
{
// base case 
if(start>end){
    return NULL;
    }
    // 1 case hm solve krege 
int mid = (start+end)/2;
 int element = inorder[mid];
Node*root  = new Node(element);

// baki recursion sambhal lega 
root->left = BSTfromInorder(inorder,start,mid-1);
root->right = BSTfromInorder(inorder,mid+1,end);

return root;

}

void CONVERT_BSTtoDLL(Node* root, Node* &head){
    if(root==NULL){
        return;
    }
    // RNL
    // R 
    CONVERT_BSTtoDLL(root->right,head);

    // N
    //  next = right
   // prev = left
    // attaching current node pointer into head of LL
    root->right  = head;
    // attaching  prev pointer of head of LL into current Node
    if(head!=NULL)
    head->left = root;
    // head update
    head = root;

    // L
    CONVERT_BSTtoDLL(root->left,head);
   

}
void PrintDLL(Node* head){
Node *temp = head;
cout<<"printing entire LL "<<endl;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->right;
}
cout<<endl;
}




int main(){
    int inorder[]={10,20,30,40,50,60,70};
    int size= 7;
    int start = 0;
    int end = size-1;
cout<<" BST from Inorder"<<endl;
    Node *root = BSTfromInorder(inorder,start,end);
    
    levelOrderTraversal(root);
Node* head = NULL;
CONVERT_BSTtoDLL(root,head);
PrintDLL(head);

}
