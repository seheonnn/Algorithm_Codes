//#include <stdio.h>
//
//int main()
//{
//	int a, b, c;
//	int day;
//
//	scanf("%d %d %d", &a, &b, &c);
//
//	for (int i = 1;; i++)
//	{
//		if ((i%a == 0) && (i%b == 0) && (i%c == 0))
//		{
//			day = i;
//			break;
//		}
//	}
//	printf("%d\n", day);
//}

//
//#include <stdio.h>
//
//int main()
//{
//	int n;
//	int num[10000] = { 0, };
//	int tmp = 23;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", num);
//		for (int k = 0; k < n; k++)
//		{
//			if ((tmp >= num[k])&&(num[k]!=0))
//			{
//				tmp = num[k];
//			}
//		}
//	}
//	printf("%d\n", tmp);
//
//}
//
//#include <stdio.h>
//#define N 19
//
//void reverse(int (*arr)[N], int x, int y)
//{
//	
//	for (int i = 0; i < N ; i++)
//	{
//		if (arr[x][i] == 0)
//			arr[x][i] = 1;
//		else
//			arr[x][i] = 0;
//	}
//	for (int j = 0; j < N ; j++)
//	{
//		if (arr[j][y] == 0)
//			arr[j][y] = 1;
//		else
//			arr[j][y] = 0;
//	}
//}
//
//int main()
//{
//	int n, x, y;
//	int arr[N][N] = {};
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	scanf("%d", &n);
//	for (int k = 0; k < n; k++)
//	{
//		scanf("%d %d", &x, &y);
//		reverse(arr, x - 1, y - 1);
//	}
//	
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}




//#include <stdio.h>
//
//int main()
//{
//	int l, d, x, y;
//	int n, w, h;
//	int i, j, k;
//	int arr[100][100] = { 0, };
//
//	scanf("%d %d", &h, &w);
//	scanf("%d", &n);
//
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d %d %d %d", &l, &d, &y, &x);
//		if (d == 0)
//		{
//			for (j = 0; j < l; j++)
//			{
//				if ((x + (l-1)) <= w)
//					arr[x + j][y] = 1;
//				else
//					arr[x - j][y] = 1;
//			}
//		}
//		else if (d == 1)
//		{
//			for (k = 0; k < l; k++)
//			{
//				if ((y + (l - 1)) <= h)
//					arr[x][y + k] = 1;
//				else
//					arr[x][y - k] = 1;
//			}
//		}
//
//	}
//	for (i = 1; i <= h; i++)
//	{
//		for (j = 1; j <= w; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//}

//#include <stdio.h>
//
//int main()
//{
//	int arr[11][11] = { 0, };
//	int x = 2, y = 2;
//
//	int i, j;
//	for (i = 1; i <= 10; i++)
//	{
//		for (j = 1; j <= 10; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	//(2,2) 개미집
//
//	while (1)
//	{
//
//		if (arr[y][x] == 0)
//		{
//			arr[y][x] = 9;
//			x++;
//		}
//		else if (arr[y][x] == 1)
//		{
//			x--;
//			y++;
//		}
//		if (arr[y][x] == 2)
//		{
//			arr[y][x] = 9;
//			break;
//		}
//
//	}
//
//	for (i = 1; i <= 10; i++)
//	{
//		for (j = 1; j <= 10; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}




//1090
//#include <stdio.h>
//
//int main()
//{
//	long long int a, r, n;
//	long long int arr[1000] = { 0, };
//
//	scanf("%lld %lld %lld", &a, &r, &n);
//
//	arr[1] = a;
//	for (int i = 2; i < 1000; i++)
//	{
//		arr[i] = arr[i - 1] * r;
//	}
//	printf("%lld\n", arr[n]);
//}


//1085
//#include <stdio.h>
//
//int main()
//{
//	double r;
//	long long int h, b, c, s;
//	scanf("%lld %lld %lld %lld", &h, &b, &c, &s);
//	r = (h*b*c*s) / 8;
//	printf("%.1lf MB\n", r / (1024 * 1024));
//
//}



//1079
//#include <stdio.h>
//
//int main()
//{
//	char c = 0;
//
//	while (c != 'q')
//	{
//		scanf("%c ", &c);
//		printf("%c\n", c);
//	}
//}


//1071
//#include <stdio.h>
//
//int main()
//{
//	long int i = 1;
//
//	while (1)
//	{
//		scanf("%ld ", &i);
//		if (i == 0)
//			break;
//		printf("%ld\n", i);
//	}
//}



////1045
//#include <stdio.h>
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d\n", a + b);
//	printf("%d\n", a - b);
//	printf("%d\n", a*b);
//	printf("%d\n", a / b);
//	printf("%d\n", a%b);
//	printf("%.2lf\n", (double)a / b);
//}

//회의실 알고리즘
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;
	return 0;
}

int main()
{
	int n, i, k;
	int s[100000];
	int f[100000];
	int cnt = 0;
	int cur = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &s[i], &f[i]);

	qsort(f, n, sizeof(int), compare);

	for (i = 0; i < n; i++)
		printf("%d ", f[i]);


	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cnt++;
			k = f[i];
		}
		else
		{
			if (s[i] >= k)
			{
				cnt++;
				k = f[i];
			}
		}
	}
	printf("%d", cnt);
}