//�ڷᱸ�� Ʈ�� ����

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



//���� ��ȸ

void preorderPrint(node* root)

{

	if (root == NULL)

		return;

	printf("%d", root->data);

	preorderPrint(root->left);

	preorderPrint(root->right);

}



//���� ��ȸ

void inorderPrint(node* root)

{

	if (root == NULL)

		return;

	inorderPrint(root->left);

	printf("%d", root->data);

	inorderPrint(root->right);

}



//���� ��ȸ

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



	printf("������ȸ\n");

	preorderPrint(root);

	printf("\n");



	printf("���� ��ȸ\n");

	inorderPrint(root);

	printf("\n");



	printf("���� ��ȸ\n");

	postorderPrint(root);

	printf("\n");



	return 0;

}