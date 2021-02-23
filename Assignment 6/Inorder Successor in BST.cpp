#include<bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 
Node* newNode(int val) 
{ 
	Node* temp = new Node; 
	temp->data = val; 
	temp->left = NULL; 
	temp->right = NULL; 
	
	return temp; 
} 
void inorderSuccessor(Node* root, Node* target_node, Node* &next) 
{ 
	if(!root) 
		return; 

	inorderSuccessor(root->right, target_node, next); 
	
	if(root->data == target_node->data) 
	{ 
		if(next == NULL) 
			cout << "inorder successor of " << root->data << " is: null\n"; 
		else
			cout << "inorder successor of "<< root->data << " is: "<< next->data << "\n"; 
	} 
	next = root; 
	inorderSuccessor(root->left, target_node, next); 
} 
int main() 
{ 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 

	Node* next = NULL; 
	inorderSuccessor(root, root->right, next); 

	next = NULL; 
	inorderSuccessor(root, root->left->left, next); 

	next = NULL; 
	inorderSuccessor(root, root->right->right, next); 
	
	return 0; 
} 

