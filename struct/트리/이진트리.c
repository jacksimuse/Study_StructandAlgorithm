#include <stdio.h>

typedef struct btnode
{
	char data;
	struct btnode* left;
	struct btnode* right;
}BTNode;

BTNode* makeBTNode(data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void makeLeftTree(BTNode* root, BTNode* sub)
{
	if (root->left != NULL) free(root->left);
	root->left = sub;
}

void makeRightTree(BTNode* root, BTNode* sub)
{
	if (root->right != NULL) free(root->right);
	root->right = sub;
}

void preorder(BTNode* root) // 전위순회 : 데이터->왼쪽서브->오른쪽서브
{
	if (root == NULL) return;
	printf("%c  ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(BTNode* root) // 중위순회
{
	if (root == NULL) return;
	inorder(root->left);
	printf("%c  ", root->data);
	inorder(root->right);
}

void postorder(BTNode* root) // 후위순회
{
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%c  ", root->data);
}

int main()
{
	BTNode* b1 = makeBTNode('a');
	BTNode* b2 = makeBTNode('b');
	BTNode* b3 = makeBTNode('c');
	BTNode* b4 = makeBTNode('d');
	BTNode* b5 = makeBTNode('e');
	BTNode* b6 = makeBTNode('f');
	BTNode* b7 = makeBTNode('g');
	BTNode* b8 = makeBTNode('h');

	makeLeftTree(b1, b2);
	makeRightTree(b1, b3);
	makeLeftTree(b2, b4);
	makeRightTree(b2, b5);
	makeLeftTree(b3, b6);
	makeRightTree(b3, b7);
	makeLeftTree(b4, b8);

	preorder(b1);
	printf("\n");
	inorder(b1);
	printf("\n");
	postorder(b1);
	printf("\n");
	return 0;
}