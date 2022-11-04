//창의적 알고리즘 중급 치즈 문제

#include <iostream>

 

using namespace std;

struct point{int y, x;};

 

int n, m, day, cnt=0, a[101][101];

int dy[]={0,1,0,-1}, dx[]={1,0,-1,0};

bool safe(int y, int x) {return 0<=y && y<n && 0<=x && x<m;}

 

void Prt()

{

    cout << endl;

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<m;j++)

        {

            cout << a[i][j] << " ";

        }

        cout << endl;

    }

    cout << endl;

}

 

dfs(int y, int x)

{

    a[y][x] = 1;

 

    for(int i=0, y1, x1; i < 4 ; i++)

    {

        y1 = y + dy[i], x1 = x + dx[i];

        if (safe(y1,x1)) 

        {

            if(a[y1][x1] == 0)   dfs(y1,x1);

            if(a[y1][x1] >= 2)   a[y1][x1]++;            

        }

 

    }

}

 

int refine()

{

    for(int i = 0 ; i < n ; i++)

    {

        for(int j = 0 ; j < m ; j++)

        {

            if(a[i][j] >= 4)  a[i][j] = 0,cnt--;

            if(a[i][j] == 1)  a[i][j] = 0;

        }

    }

    return cnt;

}

 

int main()

{

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)

    {

        for(int j = 0 ; j < m ; j++)

        {

            cin >> a[i][j];

            if (a[i][j] == 1) a[i][j]=2,cnt++;

        }

    }

 

    for(day=1; refine(); day++)

    {

        Prt();

        dfs(0,0);

    }

    cout << day;

}