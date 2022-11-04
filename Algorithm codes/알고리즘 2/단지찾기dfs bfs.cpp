/*

//단지 찾기

#include <iostream>

#include <algorithm>

#include <queue>

 

using namespace std;

struct point { int y,x; };

 

int n,a[1000][1000], k=0, Cnt[1000];

int dy[]={0,1,0,-1}, dx[] = {1,0,-1,0};

bool safe(int y, int x) { return 0<=y && y<n && 0<=x && x<n; }

 

void Prt()

{

    cout << endl;

    for(int i =0; i < n;i++)

    {

        for(int j=0;j<n;j++) cout << a[i][j] << ' ';

        cout << endl;

    }

}

 

void dfs(int y, int x, int no)

{

    //Prt();

    a[y][x] = no + 5;

    Cnt[no]++;

    //위치찾기 부분

    for(int i=0,y1,x1; i<4; i++)

    {

        y1=y+dy[i], x1=x+dx[i];

        if(safe(y1,x1) && a[y1][x1] == 1)

        {

            dfs(y1,x1,no);

        }

    }

}

 

 

void bfs(int y, int x, int no)

{

    queue<point> q;

 

    a[y][x] = no + 5;

    Cnt[no]++;

    q.push({y,x});

    while(q.size())

    {

        auto d = q.front(); q.pop();

        //위치찾기 부분

 

        for(int i=0,y1,x1; i<4; i++)

        {

            y1=y+dy[i], x1=x+dx[i];

            if(safe(y1,x1) && a[y1][x1] == 1)

            {

                Cnt[no]++;

                a[y1][x1] = no + 5;

                q.push({y1,x1});

            }

        }

    }

}

 

int main()

{

    cin >> n;

    for(int i =0; i < n;i++)for(int j=0;j<n;j++)  cin >> a[i][j];

    for(int i =0; i < n;i++)for(int j=0;j<n;j++)

    {

        if(a[i][j] == 1)

        {

            dfs(i,j,k++);

        }

    }

    cout << k << endl;

    sort(Cnt, Cnt+k);

    for(int i =0; i < k;i++)

    {

        cout << Cnt[i] << endl;

    }

}

 

 

#include <iostream>

#include <algorithm>

#include <queue>

 

using namespace std;

struct point { int y,x; };

 

int n,a[1000][1000], k=0, Cnt[1000];

int dy[]={0,1,0,-1}, dx[] = {1,0,-1,0};

bool safe(int y, int x) { return 0<=y && y<n && 0<=x && x<n; }

 

void Prt()

{

    cout << endl;

    for(int i =0; i < n;i++)

    {

        for(int j=0;j<n;j++) cout << a[i][j] << ' ';

        cout << endl;

    }

}

 

void dfs(int y, int x, int no)

{

    //Prt();

    a[y][x] = no + 5;

    Cnt[no]++;

    //위치찾기 부분

    for(int i=0,y1,x1; i<4; i++)

    {

        y1=y+dy[i], x1=x+dx[i];

        if(safe(y1,x1) && a[y1][x1] == 1)

        {

            dfs(y1,x1,no);

        }

    }

}

 

 

void bfs(int y, int x, int no)

{

    queue<point> q;

 

    a[y][x] = no + 5;

    Cnt[no]++;

    q.push({y,x});

    while(q.size())

    {

        y = q.front().y, x = q.front().x; q.pop();

        //위치찾기 부분

        //Prt();

 

        for(int i=0,y1,x1; i<4; i++)

        {

            y1=y+dy[i], x1=x+dx[i];

            if(safe(y1,x1) && a[y1][x1] == 1)

            {

                Cnt[no]++;

                a[y1][x1] = no + 5;

                q.push({y1,x1});

            }

        }

    }

}

 

int main()

{

    cin >> n;

    for(int i =0; i < n;i++)for(int j=0;j<n;j++)  cin >> a[i][j];

    for(int i =0; i < n;i++)for(int j=0;j<n;j++)

    {

        if(a[i][j] == 1)

        {

            bfs(i,j,k++);

        }

    }

    cout << k << endl;

    sort(Cnt, Cnt+k);

    for(int i =0; i < k;i++)

    {

        cout << Cnt[i] << endl;

    }

}

*/