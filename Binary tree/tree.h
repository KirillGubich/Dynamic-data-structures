#include <stdio.h>

typedef int T;
typedef struct node* TREE;

struct node {
	T key;
	struct node* left;
	struct node* right;
};

void insertElement(TREE *root, T data);
void print_Tree(TREE p, int level);
void directTraversal(TREE tree);
struct node* getNodeByValue(TREE root, T value);
struct node* getMaxNode(TREE root);
struct node* minValueNode(struct node* node);
TREE deleteNode(TREE root, T key);
int heightOfTree(TREE node);