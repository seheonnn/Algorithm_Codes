//자료구조 트리 구현

#include <stdio.h>

#include <stdlib.h>



typedef struct node

{

	int data;

	struct node* left;

	struct node* right;

}Node;



Node* newNode(int data)

{

	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;



	node->left = NULL;

	node->right = NULL;

	return(node);

}



//전위 순회

void preorderPrint(node* root)

{

	if (root == NULL)

		return;

	printf("%d", root->data);

	preorderPrint(root->left);

	preorderPrint(root->right);

}



//중위 순회

void inorderPrint(node* root)

{

	if (root == NULL)

		return;

	inorderPrint(root->left);

	printf("%d", root->data);

	inorderPrint(root->right);

}



//후위 순회

void postorderPrint(node* root)

{

	if (root == NULL)

		return;

	postorderPrint(root->left);

	postorderPrint(root->right);

	printf("%d", root->data);

}



int main()

{

	Node* root = newNode(1);



	root->left = newNode(2);

	root->right = newNode(3);



	root->left->left = newNode(4);

	root->left->right = newNode(5);



	root->right->left = newNode(6);

	root->right->right = newNode(7);



	printf("전위순회\n");

	preorderPrint(root);

	printf("\n");



	printf("중위 순회\n");

	inorderPrint(root);

	printf("\n");



	printf("후위 순회\n");

	postorderPrint(root);

	printf("\n");



	return 0;

}