//����

#include <stdio.h>



int main()

{

	char stack[5];

	char car = 'A';

	int top = 0;

	int m;



	while (1)

	{

		printf("<1> �ֱ� <2> ���� <3> ������ : ");

		scanf("%d", &m);

		if (m == 1)

		{

			if (top >= 5)

				printf("�� �̻� ���� �ڸ��� ����\n");

			else

			{

				stack[top] = car;

				printf("%c �ڵ��� push \n", stack[top]);

				top++;

				car++;

			}

		}

		else if (m == 2)

		{

			if (top <= 0)

				printf("�� �̻� �� �ڵ����� ����\n");

			else

			{

				top--;

				printf("%c �ڵ��� pop \n", stack[top]);

				stack[top] = ' ';

			}

		}

		else if (m == 3)

		{

			printf("���� %d�밡 ����\n", top);

			break;

		}

		else

			printf("�ٽ� �Է��ϼ���.\n");

	}

}