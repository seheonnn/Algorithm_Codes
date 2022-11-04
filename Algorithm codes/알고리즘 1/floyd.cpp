//플루이드 알고리즘

#include <stdio.h>
#include <stdlib.h>
#define Count_Vertice 6
#define Far_Distance 2000

int W[Count_Vertice][Count_Vertice] = {
	{0,Far_Distance,2,3,3,6},
	{Far_Distance,0,Far_Distance,4,2,Far_Distance},
	{10,2,0,5,1,Far_Distance},
	{Far_Distance,Far_Distance,4,0,Far_Distance,2},
	{5,9,Far_Distance,4,0,3},
	{Far_Distance,Far_Distance,Far_Distance,4,Far_Distance,0}
};


int D[Count_Vertice][Count_Vertice];
int P[Count_Vertice][Count_Vertice];

void Floyd() {
	int i, j, k;
	for (i = 0; i < Count_Vertice; i++)
		for (j = 0; Count_Vertice; j++) {
			P[i][j] = -1;
			D[i][j] = W[i][j];
		}
	for (k = 0; k < Count_Vertice; k++)
		for (i = 0; i < Count_Vertice; i++)
			for (j = 0; j < Count_Vertice; j++)
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j];
				}
}

void Print_Path(int a, int b) {
	if (P[a][b] != -1) {
		Print_Path(a, P[a][b]);
		printf("%d", P[a][b]);
		Print_Path[P[a][b], b];
	}
}

int main(int argc, char* argv[]) {
	Floyd();
	int a, b;
	printf("출발점과 도착점을 입력하시오.(0~%d)\n", Count_Vertice - 1);
	scanf("%d %d", &a, &b);
	printf("최단거리 : %d\n", D[a][b]);
	printf("최단경로 : ");
	printf("%d", a);
	Print_Path(a, b);
	if (D[a][b] != 0)
		printf("%d", b);
	return 0;
}