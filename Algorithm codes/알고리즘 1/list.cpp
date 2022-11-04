//리스트



#include <stdio.h>

#include <malloc.h>



typedef struct _node {

	int data;

	_node* link;

}node;





void push(node* root, int data)

{

	node* newNode = (node*)malloc(sizeof(node));



	newNode->link = root->link;

	root->link = newNode;

	newNode->data = data;



}



void push_back(node* root, int data)

{

	node* tmp = root;



	while (tmp->link != NULL)

	{

		tmp = tmp->link;

	}

	push(tmp, data);

}



void printList(node* root)

{

	node* tmp = root;

	while (1)

	{

		printf("%d\n", tmp->data);

		if (tmp->link == NULL)

			break;

		tmp = tmp->link;

	}

}

//void pop_back(node* root)

//{

//	node *tmp = root;

//	while (tmp->link->link != NULL)

//		tmp = tmp->link;

//	tmp->link = NULL;

//}



node* pop(node* root, int data)

{

	node* tmp = root;

	if (data == 1)

	{

		tmp = root;

		tmp = root->link;

		root->link = NULL;



		free(root);

		root = tmp;

	}

	else

	{

		while (tmp->link != NULL)

		{

			if (tmp->link->data == data)

			{

				tmp->link = tmp->link->link;

				break;

			}

			tmp = tmp->link;

		}

	}

	return root;

}



int main()

{

	node* root = (node*)malloc(sizeof(node));

	int del;

	root->data = 1;

	root->link = NULL;



	node* tmp = root;



	//입력 : 2~5까지

	for (int i = 2; i < 6; i++)

	{

		push_back(root, i);

		tmp = tmp->link;

	}

	////마지막 값 삭제 (5 삭제)

	//pop_back(root);



	//출력

	printList(root);



	//원하는 값 삭제

	printf("삭제를 원하는 값 : ");

	scanf("%d", &del);

	root = pop(root, del);





	//출력

	printList(root);

}









//연결리스트(수정)

#include <stdio.h>

#include <malloc.h>

typedef struct node

{

	int data;

	struct node* link;

}Node;



void insert(node* root, int data)//가장 마지막에 값을 추가

{

	node* newNode = (node*)malloc(sizeof(node));

	while (root->link != NULL)

	{

		root = root->link;

	}

	newNode->link = root->link;

	root->link = newNode;

	newNode->data = data;

}



node* delet(node* root, int del)

{

	node* tmp = root;

	if (del == root->data)

	{

		tmp = root->link;

		root->link == NULL;

		free(root);

		root = tmp;

	}

	else

	{

		while (1)

		{

			if (tmp->link->data == del)

			{

				tmp->link = tmp->link->link;

				break;

			}

			tmp = tmp->link;

		}

	}

	return root;

}



void printList(node* root)

{

	node* tmp = root;

	while (tmp != NULL)

	{

		printf("%d\n", tmp->data);

		tmp = tmp->link;

	}

}







int main()

{

	node* root = (node*)malloc(sizeof(node));



	int del;

	root->data = 1;

	root->link = NULL;

	insert(root, 2);

	insert(root, 3);

	insert(root, 4);



	printList(root);



	printf("삭제할 data 값 : ");

	scanf_s("%d", &del);

	root = delet(root, del);

	printList(root);

}







//이중 연결 리스트 수정2

#include <stdio.h>

#include <malloc.h>



typedef struct node

{

	int data;

	struct node* llink;

	struct node* rlink;

}Node;



void pushBack(node* root, int data)//마지막에 추가

{

	node* newNode = (node*)malloc(sizeof(node));

	while (root->rlink != NULL)

	{

		root = root->rlink;

	}



	newNode->rlink = root->rlink;

	newNode->llink = root;

	root->rlink = newNode;

	newNode->data = data;

}



node* insert(node* root, int data, int loc)

{

	node* tmp = root;

	node* newNode = (node*)malloc(sizeof(node));



	newNode->data = data;



	if (loc == 1)//

	{

		newNode->rlink = root;

		newNode->llink = NULL;

		root->llink = newNode;

		root = newNode;

	}

	else

	{

		for (int i = 1; i < loc - 1; i++)

		{

			if (tmp->rlink == NULL)

				break;

			tmp = tmp->rlink;

		}

		if (tmp->rlink == NULL)//

		{

			tmp->rlink = newNode;

			newNode->llink = tmp;

			newNode->rlink = NULL;

		}

		else

		{

			newNode->rlink = tmp->rlink;

			newNode->rlink->llink = newNode;

			tmp->rlink = newNode;

			newNode->llink = tmp;

		}

	}

	return root;

}



node* delet(node* root, int del)

{

	node* tmp = root;

	if (del == root->data)

	{

		tmp = root->rlink;

		root->rlink = NULL;

		free(root);

		root = tmp;

	}

	else

	{

		while (1)

		{

			if (tmp->rlink->data == del)

			{

				tmp->rlink = tmp->rlink->rlink;

				if (tmp->rlink != NULL)

					tmp->rlink->llink = tmp;

				break;

			}

			tmp = tmp->rlink;

		}

	}

	return root;

}



void printList(node* root)

{

	node* tmp = root;

	while (tmp != NULL)

	{

		printf("%d\n", tmp->data);

		tmp = tmp->rlink;

	}

}



int main()

{

	node* root = (node*)malloc(sizeof(node));



	int data;

	int loc;



	root->data = 1;

	root->llink = NULL;

	root->rlink = NULL;



	pushBack(root, 2);

	pushBack(root, 3);

	pushBack(root, 4);

	pushBack(root, 5);



	printList(root);



	printf("삭제할 data 값 : ");

	scanf("%d", &data);

	root = delet(root, data);



	printList(root);



	printf("추가할 data 값과 위치:");

	scanf("%d %d", &data, &loc);

	root = insert(root, data, loc);



	printList(root);

}