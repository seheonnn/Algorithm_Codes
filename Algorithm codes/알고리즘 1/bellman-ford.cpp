//벨만포드 알고리즘
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

struct edge {
	int to, cost;
};

vector<edge> graph[1003];
int dist[1003];

int bellmanFord(int s, int v)//s : 시작 정점, v : 정점 개수
{
	for (int i = 1; i <= v; i++)//dist 초기화
		dist[i] = INF;
	dist[s] = 0;
	bool updated;

	for (int i = 0; i < v; i++)//v번 반복
	{
		;
		updated = false;
		for (int cur = 1; cur <= v; cur++)//모든 간선을 확인해보면서 dist 갱신
		{
			if (dist[cur] == INF)
				continue;
			for (int j = 0; j < graph[cur].size(); j++)
			{
				int next = graph[cur][j].to;
				int cost = graph[cur][j].cost;
				if (dist[next] > dist[cur] + cost)
				{
					dist[next] = dist[cur] + cost;
					updated = true;
				}
			}
		}
		if (!updated)//더 이상 갱신되지 않았다면 break;
			break;
	}
	if (updated)//v번 반복했음에도 갱신되었다면 음수 사이클이 있음
		return -1;
	return 0;//아닌 경우엔 0리턴
}

int main()
{
	int n, m;

	scanf_s(" %d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf_s(" %d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c, });
	}
	if (bellmanFord(1, n) == -1)
		printf("음수 사이클이 있음\n");
	else
		for (int i = 2; i <= n; i++)
			printf("%d\n", dist[i] < INF ? dist[i] : -1);
	return 0;
}