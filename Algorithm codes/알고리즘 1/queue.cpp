//큐

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

		printf("<1> 넣기 <2> 빼기 <3> 끝 : ");

		scanf("%d", &m);

		if (m == 1)

		{

			if (end >= N)

				end = end % N;

			if (queue[end] == 0)

			{

				queue[end] = car;

				printf("%c 자동차 push\n", queue[end]);

				end++;

				car++;

				k++;

			}

			else

				printf("더 이상 넣을 자리가 없음\n");

		}

		else if (m == 2)

		{

			if (st >= N)

				st = st % N;

			if (queue[st] != 0)

			{

				printf("%c 자동차 pop\n", queue[st]);

				queue[st] = 0;

				st++;

				k--;

			}

			else

				printf("더 이상 뺄 자동차가 없음\n");

		}

		else if (m == 3)

		{

			printf("현재 %d 대가 있음\n", k);

			break;

		}

		else

			printf("다시 입력하세요.\n");



		//printf("%d %d\n", st, end);

	}

}





//원형큐

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

		printf("<1> 넣기 <2> 빼기 <3> 끝 : ");

		scanf("%d", &m);

		if (m == 1)

		{

			printf("넣을 자동차의 이름 : ");

			scanf(" %c", &car);

			if (end >= N)

				end = end % N;

			if (queue[end] == 0)

			{

				queue[end] = car;

				printf("%c 자동차 push\n", queue[end]);

				end++;

				k++;

			}

			else

				printf("더 이상 넣을 자리가 없음\n");

		}

		else if (m == 2)

		{

			if (st >= N)

				st = st % N;

			if (queue[st] != 0)

			{

				printf("%c 자동차 pop\n", queue[st]);

				queue[st] = 0;

				st++;

				k--;

			}

			else

				printf("더 이상 뺄 자동차가 없음\n");

		}

		else if (m == 3)

		{

			printf("현재 %d 대가 있음\n", k);

			break;

		}

		else

			printf("다시 입력하세요.\n");

	}

}