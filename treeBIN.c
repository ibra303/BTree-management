#include "TreeHeader.h";
// Tree Hight
int TreeHight(BTT tree)
{
	int NodeLHight, NodeRHight;
	if (!tree)
		return -1;
	NodeLHight = TreeHight(tree->left);
	NodeRHight = TreeHight(tree->right);
	return 1 + Max(NodeLHight, NodeRHight);
}

// tree make and insert
BTT MakeTreeInt(int data, BTT p)
{
	// check if root is null
	if (!p)
	{
		p = (BTT)malloc(sizeof(BT));
		if (!p) {printf("error, malloc did not work\n");}
		p->key = data;
		p->left = NULL;
		p->right = NULL;
		printf("%d was added to the tree\n\n", data);
		return(p);
	}
	if (data == p->key) { printf("error, this element is already in the tree\n\n"); }
	if (data < p->key) {p->left = MakeTreeInt(data, p->left);}
	else
		if (data > p->key) {p->right = MakeTreeInt(data, p->right); }
	return p;
}

// inroder print
void printInorder(BTT tree)
{
	if (tree == NULL)
		return;
	//go left
	printInorder(tree->left);
	printf("%d\n", tree->key);
	// go right 
	printInorder(tree->right);
}

//go to right until the right is null and return the biggest num 
BTT MaxNum(BTT tree)
{
	if (tree != NULL)
		while (tree->right != NULL)
			tree = tree->right;
	return tree;
}

// search if key in the tree 
int findElement(BTT root, int value) {
	if (root != NULL) {
		if (root->key == value) {
			return 1;
		}
		else {
			//  calls to enter right or left to check element
			return findElement(root->left, value) || findElement(root->right, value);
		}
	}
	return 0;
}
// count nodes in our tree 
int countNode(BTT root) {

	if (root == NULL)
		return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}
// serach for the k smallest elements, this funcs
// we used the trick of print in order to print from the smallest element until the k small one
void ksmallestElement(BTT root, int k,int *count)
{ 
		if ((!root) || (*count >= k))  
			return;
		// go left
		ksmallestElement(root->left, k,count);

		if (*count < k)
		{ 
			(*count)++;
			printf("%d ", root->key);       
		}
		//go right
		ksmallestElement(root->right, k, count); 
}
// run ksmallestElement with counter to sum the calls of the func
void PrintksmallestElement(BTT root, int k)
{
		int count = 0;
		ksmallestElement(root,k,&count);
}