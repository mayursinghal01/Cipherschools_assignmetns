/* C++ program to construct tree using inorder and 
postorder traversals */
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *left, *right;
};
Node* newNode(int data);
Node* buildUtil(int in[], int post[], int inStrt,int inEnd, int* pIndex, unordered_map<int, int>& mp)
{
	if (inStrt > inEnd)
		return NULL;
	int curr = post[*pIndex];
	Node* node = newNode(curr);
	(*pIndex)--;
	if (inStrt == inEnd)
		return node;
	int iIndex = mp[curr];
	node->right = buildUtil(in, post, iIndex + 1,inEnd, pIndex, mp);
	node->left = buildUtil(in, post, inStrt,iIndex - 1, pIndex, mp);

	return node;
}
struct Node* buildTree(int in[], int post[], int len)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;

	int index = len - 1;
	return buildUtil(in, post, 0, len - 1,&index, mp);
}
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}
int main()
{
	int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
	int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
	int n = sizeof(in) / sizeof(in[0]);
	Node* root = buildTree(in, post, n);
	cout << "Preorder of the constructed tree : \n";
	preOrder(root);
	return 0;
}
