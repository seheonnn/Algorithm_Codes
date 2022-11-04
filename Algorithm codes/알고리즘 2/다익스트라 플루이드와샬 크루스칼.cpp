////다익스트라
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//#define INF 999
//
//using namespace std;
//
//vector<int> d,v;
//
//int n, m;
//int GSHS = 1;
//
//struct Node {
//    vector<pair<int, int>> cld;
//};
//
//Node nd[20];
//
////void prt()
////{
////    for(auto k : d) printf("%3d ", k);
////    cout << endl;
////    for(auto k : v) printf("%3d ", k);
////    cout << endl;cout << endl;
////}
//
//void dijkstra(int start)
//{
//    fill(d.begin()+1,d.end(),INF);
//    d[start] = 0;
//    int idx;
//    for(int i=1; i<=n; i++)
//    {
//        int mn = INF;
//        for(int j=1; j<=n; j++)
//        {
//            if(!v[j] && d[j] < mn) { mn = d[j], idx = j; }
//        }
//        v[idx] = 1;
//
//        for(auto p : nd[idx].cld)//nd[idx].cld 하나씩 p에 받음
//        {
//            if(d[p.first] > d[idx] + p.second)  d[p.first] = d[idx] + p.second;
//        }
////        prt();
//    }
//}
//
//int main()
//{
//    cin >> n >> m;
//
//    d.resize(n+1), v.resize(n+1);
//    for(int i=1,a,b,c; i<=m; i++)
//    {
//        cin >> a >> b >> c;
//        nd[a].cld.push_back({b,c});
//    }
//
//    dijkstra(GSHS);
//
//    if(d[n] == INF) cout << -1;
//    else cout << d[n];
//}
 
 
////플루이드 와샬
//#include <iostream>
//#include <algorithm>
//
//#define INF 999
//
//using namespace std;
//
//int n ,m;
//int g[20][20];
//
//void floyd_washall()
//{
//    for(int k=1;k<=n;k++)
//        for (int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//                if(g[i][j] > g[i][k] + g[k][j])    g[i][j] = g[i][k] + g[k][j];
//}
//
//int main()
//{
//    int a, b, c;
//    cin >> n >> m;
//    for(int i=1;i<=n;i++ )  fill(g[i],g[i]+(n+1),INF);
//    for(int i=1;i<=m;i++ )
//    {
//        cin >> a >> b >> c;
//        g[a][b] = g[b][a] = c;
//    }
//
//    floyd_washall();
//
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            g[i][i]=0;
//            if(g[i][j] == INF) cout << -1 << "   ";
//            else cout << g[i][j] << "   ";
//        }
//        cout <<endl;
//    }
//}
 
 
//최소비용신장 트리(크루스칼) 백준 1197번 https://baebalja.tistory.com/317
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int parent[10001], v, e, result = 0;
 
int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}
 
void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}
 
bool sameParent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}
 
int main()
{
    cin >> v >> e;
 
        vector<pair<int, pair<int, int>>> nd;
 
    int from, to, cost;
    for (int i = 1; i <= e; i++)
    {
        cin >> from >> to >> cost;
        nd.push_back({ cost, {from, to} });
    }
    sort(nd.begin(), nd.end());
    for (int i = 1; i <= v; i++) parent[i] = i;
    for (int i = 0; i < nd.size(); i++) 
    {
        if (!sameParent(nd[i].second.first, nd[i].second.second)) {
            uni(nd[i].second.first, nd[i].second.second);
            result += nd[i].first;
        }
    }
    cout << result;
}