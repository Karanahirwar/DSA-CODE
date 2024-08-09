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
  cout<<" enter your data:"<<endl;
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

// minimum and maximum of binary search tree 


// minimum value 

Node* MinValue(Node*root){
	if(root==NULL){
		cout<<" minValue is not exits "<<endl;
		return NULL;
	}
     Node*temp = root;

	 while(temp->left!=NULL){
		temp = temp->left;
	 }
	 return  temp;
	 
}

// maximum value 

Node* MaxValue(Node*root){
	if(root==NULL){
		cout<<" maxValue is not exits "<<endl;
		return NULL;
	}
     Node*temp = root;
	while(temp->right!=NULL){
		temp = temp->right;
	 }
	 return  temp;
	 
}

bool binarySearch(Node* root,int target)
{
	// base case 
	if(root==NULL){
		return false;
	}

	// ek case hm solve krege 
	if(target==root->data){
		return true;
	}
	// baki recursion sambhal lega 
	bool leftans = false;
	bool rightans = false;
	if(target>root->data)
	{
     rightans= binarySearch(root->right,target);

	}
	else{
     leftans= binarySearch(root->left,target);

	}
 return rightans || leftans;
}

Node* deleteBST(Node*root,int target){
	// target dhudo 
	// delete node

// base case 
if(root==NULL){
	delete root;
	return NULL;
}

if(root->data == target){
	// 4 case create 

	// case 1 -> left and right both NULL
	if(root->left==NULL && root->right==NULL ){
		delete root;
		return NULL;
	}
	// case 2 -> left is nULL  and right not  NULL
	else if(root->left==NULL && root->right!=NULL ){

		Node *childsubtree = root->right;
		delete root;
		return childsubtree;
		 
	}

	// case 3 -> left is not  nULL  and right is  NULL
	else if(root->left!=NULL && root->right==NULL ){
		Node *childsubtree = root->left;
		delete root;
		return childsubtree;
	}
	// case 4-> left and right both not NULL 
	// else {
    //   // a-> left sub tree ki maximum value 
    //  Node*maxi = MaxValue(root->left);
	//  root->data = maxi->data;

	// root->left = deleteBST(root->left, maxi->data);
   
    //   return root;
	// }
	
	// OR 

	else {
      // b-> right sub tree ki minimum value 
     Node*mini = MinValue(root->right);
	 // root ke data ko mini ke minimum of subtree se replace krege  
	 root->data = mini->data;
     // connection reagain bna rhe h 
	    root->right = deleteBST(root->right, mini->data);
   // important  understandable point 
      return root;
	}
}

else if (root->data >target){
	// left me jao 
	root->left = deleteBST(root->left, target);
	//yha galti karoge 
	// root ka sub tree update ho chuka h 
	
}

else{
	// right me jao 
	root->right =  deleteBST(root->right, target);
	//yha galti karoge 

	// root ka sub tree update ho chuka h 

}

return root;

}




int main(){
    Node*root = NULL;
 	CreatBST(root);



cout<<"printing levelorder  traversal"<<endl;
levelOrderTraversal(root);

cout<<"printing preorder traversal"<<endl;
PreOrederTraversal(root);

cout<<endl;

cout<<"printing INorder traversal"<<endl;
InOrederTraversal(root);
cout<<endl;

cout<<"printing postorder traversal"<<endl;
PostOrederTraversal(root);
cout<<endl;
cout<<endl;
Node* MINVAlUE = MinValue(root);
if(MINVAlUE==NULL){
	cout<<" Minvalue is not exits"<<endl;
}
else{
	cout<<" MINvalue is : "<< MINVAlUE->data <<endl;
}
cout<<endl;


Node* MAXVAlUE = MaxValue(root);
if(MAXVAlUE==NULL){
	cout<<" Maxvalue is not exits"<<endl;
}
else{
	cout<<" MAXvalue is : "<< MAXVAlUE->data <<endl;
}


// int target;
// cout<<" enter your target:";
// cin>>target;


// // -1 ke case me jukna h 
// while(target!=-1){
// 	   bool ans = binarySearch(root,target);
// if(ans == true){
// 	cout<<"found target"<<endl;
// }

// else{
// 	cout<<"not found target:"<<endl;
// }

//  cout<<endl;
//  cout<<" enter your target:";
// cin>>target;
// }


int target;
cout<<" enter your target:";
cin>>target;

while(target != -1){
root = deleteBST(root,target);
cout<<endl;
cout<<" printing level order traversal "<<endl;
levelOrderTraversal(root);

cout<<" enter your target:";
cin>>target;

}

  return 0;

}