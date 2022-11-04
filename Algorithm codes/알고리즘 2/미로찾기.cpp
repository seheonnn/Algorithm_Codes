#include <iostream>
#include <queue>

using namespace std;

struct point { int y, x; };

int w, h, day = 0, Cnt = 0, Tcnt=0;
int s1, s2;
int a[1000][1000];
int dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };
bool safe(int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; }

point S,G;

void Prt()
{
    cout << endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++) cout << a[i][j] << ' ';
        cout << endl;
    }
}

queue<point> q;

int bfs()
{
    a[S.y][S.x] = 0;
    q.push({S.y,S.x});

    for(int y,x ; q.size() ; )
    {
        y = q.front().y, x = q.front().x; q.pop();

        Prt();
        if(y == G.y && x == G.x)
        {
            return a[y][x];
        }

        for (int i = 0, y1, x1; i < 4; i++)
        {
            y1 = y + dy[i], x1 = x + dx[i];
            if (safe(y1, x1) && a[y1][x1] == -1)
            {
                a[y1][x1] = a[y][x] + 1;
                q.push({ y1,x1 });
            }
        }
    }
    return -1;
}

int main()
{
    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        char s[1000];
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            if (s[j] == 'S') S.y = i, S.x = j;
            if (s[j] == 'G') G.y = i, G.x = j;

            if (s[j] == '#') a[i][j]=-2;
            else             a[i][j]=-1;
        }
    }

    cout << bfs();
}