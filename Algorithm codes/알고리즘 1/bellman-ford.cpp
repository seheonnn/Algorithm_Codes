//�������� �˰���
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

int bellmanFord(int s, int v)//s : ���� ����, v : ���� ����
{
	for (int i = 1; i <= v; i++)//dist �ʱ�ȭ
		dist[i] = INF;
	dist[s] = 0;
	bool updated;

	for (int i = 0; i < v; i++)//v�� �ݺ�
	{
		;
		updated = false;
		for (int cur = 1; cur <= v; cur++)//��� ������ Ȯ���غ��鼭 dist ����
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
		if (!updated)//�� �̻� ���ŵ��� �ʾҴٸ� break;
			break;
	}
	if (updated)//v�� �ݺ��������� ���ŵǾ��ٸ� ���� ����Ŭ�� ����
		return -1;
	return 0;//�ƴ� ��쿣 0����
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
		printf("���� ����Ŭ�� ����\n");
	else
		for (int i = 2; i <= n; i++)
			printf("%d\n", dist[i] < INF ? dist[i] : -1);
	return 0;
}