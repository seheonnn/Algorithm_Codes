#include <iostream>

#include <queue>

 

using namespace std;

#define NN 10

#define TT 10

 

struct point {int y, x;};

 

int a[NN][NN] = {0, }, n, k, grp[TT], year = 0, civCnt;

int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

 

bool safe(int y, int x) { return 0<=y && y<n && 0<=x && x<n; }

 

queue<point> q;

 

 

void Prt()

{

    cout << endl;

 

    for(int i =0; i < n;i++)

    {

        for(int j=0;j<n;j++) cout << a[i][j] << ' ';

        cout << endl;

    }

    cout << civCnt << endl;

}

 

int find_grp(int g) //각 그룹의 find_grp 비교, 같으면 같은 그룹, 다르면 다른 그룹임. 그룹끼리 만나 합칠 때는 grp 배열의 숫자만 바꿔주면 됨.

{

    if(g == grp[g]) return g;

    return grp[g]=find_grp(grp[g]);

}

 

void Push(int y, int x, int g)

{

    q.push({y,x});

Prt();

 

    for(int i=0,y1,x1; i<4; i++)

    {

        y1=y+dy[i], x1=x+dx[i];

        if(safe(y1,x1) && a[y1][x1] > 0)

        {

            int g1 = find_grp(g);

            int g2 = find_grp(a[y1][x1]);

            if(g1 != g2)

            {

                grp[g1] = g2;

                civCnt--;

                if(civCnt == 1) return;

            }

 

        }

    }

}

 

int bfs()

 

{

    for(int y,x,g;q.size();)

    {

        y = q.front().y, x = q.front().x; q.pop();

        if(y == -1)

        {

            if(civCnt == 1)  return 0;

            year++;

            q.push({-1,-1});

 

            continue;

        }

 

        g = a[y][x];

 

 

        for(int i=0,y1,x1; i<4; i++)

        {

            y1=y+dy[i], x1=x+dx[i];

            if(safe(y1,x1) && a[y1][x1] == 0)

            {

                a[y1][x1] = g;

                Push(y1,x1,g);

                if(civCnt == 1)  break;

            }

        }

 

    }

}

 

int main()

{

    int y, x;

    cin >> n >> k;

 

    for(civCnt=1; civCnt <= k; civCnt++) grp[civCnt] = civCnt;

    civCnt--;

 

    for(int i=1; i <= k; i++)

    {

        cin >> x >> y;

        x -= 1, y-= 1;

        a[x][y] = i;

        Push(y,x,i);

    }

 

 

    q.push({-1,-1});

 

    bfs();

 

    cout << year;

}