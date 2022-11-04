#include <iostream>
#include <queue>

using namespace std;

struct point {int y, x;};

int a[2000][2000] = {0, }, n, k, grp[100000], year = 0;
int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

bool safe(int y, int x) { return 0<=y && y<n && 0<=x && x<n; }

queue<point> q;

int find_grp(int g) //각 그룹의 find_grp 비교, 같으면 같은 그룹, 다르면 다른 그룹임. 그룹끼리 만나 합칠 때는 grp 배열의 숫자만 바꿔주면 됨.
{
    if(g == grp[g]) return g;
    return grp[g]=find_grp(grp[g]);
}

void Prt()
{
    cout << endl;
    for(int i =0; i < n;i++)
    {
        for(int j=0;j<n;j++) cout << a[i][j] << ' ';
        cout << endl;
    }
}

void bfs()
{
    for(int y,x;q.size();)
    {
        y = q.front().y, x = q.front().x; q.pop();

        if(y == -1)
        {
            if(q.size() == 0)   return;
            year++;
            q.push({-1,-1});
            continue;
        }

        Prt();

        for(int i=0,y1,x1; i<4; i++)
        {
            y1=y+dy[i], x1=x+dx[i];
            if(safe(y1,x1) && a[y1][x1] == 0 && a[y1][x1] != -1)
            {
                a[y1][x1] = 1;
                q.push({y1,x1});
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i=1; i<=k; i++) 
    {
        cin >> x >> y;
        a[x][y] = i;
        q.push({y,x});
    }

    for(int i=1 ; i<=k ;i++) g[i] = i;

    q.push({-1,-1});

    bfs();

    cout << year;
}