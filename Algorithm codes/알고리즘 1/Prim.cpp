//���� �˰���

#include <stdio.h>

#define TRUE 1

#define FALSE 0



#define MAX_VERTICES 7

#define INF 1000L



int weight[MAX_VERTICES][MAX_VERTICES] = {

	{0,29,INF,INF,INF,10,INF},

	{29,0,16,INF,INF,INF,15},

	{INF,16,0,12,INF,INF,INF},

	{INF,INF,12,0,22,INF,18},

	{INF,INF,INF,22,0,27,25},

	{10,INF,INF,INF,27,0,INF},

	{INF,15,INF,18,25,INF,0}

};



int selected[MAX_VERTICES];

int dist[MAX_VERTICES];



int get_min_vertex(int n)

{

	int v, i;



	for (i = 0; i < n; i++)

	{

		if (selected[i] == FALSE) {

			v = i;

			break;

		}

	}

	for (i = 0; i < n; i++)

	{

		if (selected[i] = FALSE && (dist[i] < dist[v]))

			v = i;

	}

	return(v);

}



void prim(int s, int n)

{

	int i, u, v;



	for (u = 0; u < n; u++)

	{

		dist[u] = INF;

		selected[u] = FALSE;

	}

	dist[s] = 0;



	for (i = 0; i < n; i++)

	{

		u = get_min_vertex(n);

		selected[u] = TRUE;



		if (dist[u] == INF)

			return;

		

		printf("%d ", u);



		for (v = 0; v < n; v++)

		{

			if (weight[u][v] != INF)

			{

				if (selected[v] == FALSE && weight[u][v] < dist[v])

					dist[v] = weight[u][v];

			}

		}

	}

}



void main()

{

	prim(0, MAX_VERTICES);

}

