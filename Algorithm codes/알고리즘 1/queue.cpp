//ť

#include <stdio.h>

#define N 5

int main()

{



	char queue[N] = {};

	char car = 'A';

	int st = 0, end = 0;

	int m, k = 0;

	

	while (1)

	{

		printf("<1> �ֱ� <2> ���� <3> �� : ");

		scanf("%d", &m);

		if (m == 1)

		{

			if (end >= N)

				end = end % N;

			if (queue[end] == 0)

			{

				queue[end] = car;

				printf("%c �ڵ��� push\n", queue[end]);

				end++;

				car++;

				k++;

			}

			else

				printf("�� �̻� ���� �ڸ��� ����\n");

		}

		else if (m == 2)

		{

			if (st >= N)

				st = st % N;

			if (queue[st] != 0)

			{

				printf("%c �ڵ��� pop\n", queue[st]);

				queue[st] = 0;

				st++;

				k--;

			}

			else

				printf("�� �̻� �� �ڵ����� ����\n");

		}

		else if (m == 3)

		{

			printf("���� %d �밡 ����\n", k);

			break;

		}

		else

			printf("�ٽ� �Է��ϼ���.\n");



		//printf("%d %d\n", st, end);

	}

}





//����ť

#include <stdio.h>

#define N 5

int main()

{



	char queue[N] = {};

	char car;

	int st = 0, end = 0;

	int m, k = 0;



	while (1)

	{

		printf("<1> �ֱ� <2> ���� <3> �� : ");

		scanf("%d", &m);

		if (m == 1)

		{

			printf("���� �ڵ����� �̸� : ");

			scanf(" %c", &car);

			if (end >= N)

				end = end % N;

			if (queue[end] == 0)

			{

				queue[end] = car;

				printf("%c �ڵ��� push\n", queue[end]);

				end++;

				k++;

			}

			else

				printf("�� �̻� ���� �ڸ��� ����\n");

		}

		else if (m == 2)

		{

			if (st >= N)

				st = st % N;

			if (queue[st] != 0)

			{

				printf("%c �ڵ��� pop\n", queue[st]);

				queue[st] = 0;

				st++;

				k--;

			}

			else

				printf("�� �̻� �� �ڵ����� ����\n");

		}

		else if (m == 3)

		{

			printf("���� %d �밡 ����\n", k);

			break;

		}

		else

			printf("�ٽ� �Է��ϼ���.\n");

	}

}