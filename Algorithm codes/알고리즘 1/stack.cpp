//스택

#include <stdio.h>



int main()

{

	char stack[5];

	char car = 'A';

	int top = 0;

	int m;



	while (1)

	{

		printf("<1> 넣기 <2> 빼기 <3> 끝내기 : ");

		scanf("%d", &m);

		if (m == 1)

		{

			if (top >= 5)

				printf("더 이상 넣을 자리가 없음\n");

			else

			{

				stack[top] = car;

				printf("%c 자동차 push \n", stack[top]);

				top++;

				car++;

			}

		}

		else if (m == 2)

		{

			if (top <= 0)

				printf("더 이상 뺄 자동차가 없음\n");

			else

			{

				top--;

				printf("%c 자동차 pop \n", stack[top]);

				stack[top] = ' ';

			}

		}

		else if (m == 3)

		{

			printf("현재 %d대가 있음\n", top);

			break;

		}

		else

			printf("다시 입력하세요.\n");

	}

}