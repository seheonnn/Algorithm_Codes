 //토마토 문제

 

#include <iostream>

#include <queue>

 

using namespace std;

 

struct point {int y, x;};

 

int m,n, a[1000][1000], day=0, Tcnt=0;

int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

bool safe(int y, int x) { return 0<=y && y<n && 0<=x && x<m; }

 

void Prt()

{

    cout << endl;

    for(int i =0; i < n;i++)

    {

        for(int j=0;j<m;j++) cout << a[i][j] << ' ';

        cout << endl;

    }

}

 

queue<point> q;

 

void bfs()

{

    for(int y,x; q.size(); )

    {

        y = q.front().y, x = q.front().x; q.pop();

        if(y == -1)

        {

            if(q.size() == 0)   return;

            day++;

            q.push({-1,-1});

            continue;

        }

 

        //Prt();

 

        for(int i=0,y1,x1; i<4; i++)

        {

            y1=y+dy[i], x1=x+dx[i];

            if(safe(y1,x1) && a[y1][x1] == 0 && a[y1][x1] != -1)

            {

                a[y1][x1] = 1; Tcnt--;

                q.push({y1,x1});

            }

        }

    }

}

 

int main()

{

 

    cin >> m >> n;

 

    for(int i =0; i < n;i++)for(int j=0;j<m;j++)

 

    {

        cin >> a[i][j];

        if(a[i][j] == 1) q.push({i,j});

        if(a[i][j] == 0) Tcnt++;

    }

    q.push({-1,-1});

 

    bfs();

 

    if(Tcnt != 0) cout << -1;

    else cout << day;

}