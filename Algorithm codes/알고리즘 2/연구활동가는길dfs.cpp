//창의적 알고리즘 연구활동 가는길 dfs
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999

using namespace std;

int n, m, s=1,d=7, minw=INF;

struct Node {
   vector<pair<Node*, int>> cld; //first는 자식 second는 비용
   int no,v;
};

Node nd[20];

void dfs(Node* p, int wei)
{
   if(p->no == d)
   {
       minw = min(minw,wei);
       return;
   }

   for(auto x : p->cld)
   {
       if(x.first->v == 0)
       {
           x.first->v = 1;
           dfs(x.first, wei+x.second);
           x.first->v = 0; //그래프에서는 방문체크하고 다시 원래대로 해야함. 같은 위치에 또 방문할 수 있기 때문
       }
   }
}

int main()
{
   cin >> n >> m;

   for(int i=1; i<=n; i++) nd[i].no = i;
   for(int i=1,a,b,c; i<=m; i++)
   {
       cin >> a >> b >> c;

       nd[a].cld.push_back({&nd[b],c});
       nd[b].cld.push_back({&nd[a],c});
   }

   dfs(&nd[s],0);

   if(minw == INF) cout << -1;
   else cout << minw;
}