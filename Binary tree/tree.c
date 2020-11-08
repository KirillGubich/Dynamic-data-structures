#include "Tree.h"

// Adding an item to the tree
void insertElement(TREE *root, T data)
{

	if (*root == NULL)
	{
		*root = (struct node*) malloc(sizeof(struct node));
		(*root)->key = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else
	{
		if (data <= ((*root)->key))
		{
			insertElement(&((*root)->left), data);
		}
		else
		{
			insertElement(&((*root)->right), data);
		}
	}
}

// Output the tree to the console
void print_Tree(TREE p, int level)
{
	if (p != NULL)
	{
		print_Tree(p->right, level + 1);
		for (int i = 0;i < level;i++)
		{
			printf("   ");
		}
		printf("%d\n", p->key);
		print_Tree(p->left, level + 1);
	}
}

// Direct tree traversal
void directTraversal(TREE tree)
{
	if (tree != NULL)
	{
		printf("%d, ", tree->key);
		directTraversal(tree->left);
		directTraversal(tree->right);
	}
}

// Search for a tree element by value.
// If an element is found - returns a pointer to this element / otherwise - NULL
struct node* getNodeByValue(TREE root, T value)
{
	while (root != NULL) {
		if (value < root->key) {
			root = root->left;
			continue;
		}
		else if (value > root->key) {
			root = root->right;
			continue;
		}
		else {
			return root;
		}
	}
	return NULL;
}

// Search for the maximum element in the tree (subtree)
// If an element is found - returns a pointer to this element / otherwise - NULL
struct node* getMaxNode(TREE root) 
{
	while (root->right != NULL) {
		root = root->right;
	}
	return root;
}

// Find the minimum element in the tree (subtree)
// If an element is found - returns a pointer to this element / otherwise - NULL
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	// Find the leftmost element
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

// Remove an element from a binary tree by its value
// Returns a pointer to a new tree
TREE deleteNode(TREE root, T key)
{
	// If the tree doesn't exist 
	if (root == NULL) return root;

	// If the element value is less than the root value,
// this item is in the left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the element value is greater than the root value,
// this item is in the right subtree  
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{
		// node with only one child or no child 
		if (root->left == NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node 
		root->key = temp->key;

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->key);
	}

	return root;
}

// Maximum subtree length
int heightOfTree(TREE node)
{
	if (node == NULL)
		return 0;

	int left, right;

	if (node->left != NULL) {
		left = heightOfTree(node->left);
	}
	else
		left = -1;

	if (node->right != NULL) {
		right = heightOfTree(node->right);
	}
	else
		right = -1;

	int max;
	max = left > right ? left : right;
	return max + 1;

}

