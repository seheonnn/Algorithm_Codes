//정올 3078 물통
#include <iostream>
#include <cstdio>
#include <queue>

#define NN 100001
using namespace std;

struct Data { int a,b,c; };

int chk[4][NN];
int AF,BF,RA,RB;

queue<Data> q;

void pushQ(int a, int b, int c) //a: a물통에 있는 물의 양, c: 횟수
{
    int y,x;

         if(a ==  0)  y=0,x=b;
    else if(b ==  0)  y=1,x=a;
    else if(a == AF)  y=2,x=b;
    else if(b == BF)  y=3,x=a;

    if(chk[y][x] == 0)   chk[y][x] = 1,  q.push({a,b,c});
}

int bfs()
{
    pushQ(0,0,0);

    while(q.size())
    {
        Data k = q.front(); q.pop();
        int a = k.a, b = k.b, c = k.c;

        if(a == RA && b == RB)  return c;

        {
            if(a == 0) pushQ(AF,b,c+1);
            if(b == 0) pushQ(a,BF,c+1);
            if(a ==AF) pushQ(0, b,c+1);
            if(b ==BF) pushQ(a, 0,c+1);

            int sum = a+b;
            if(sum <  AF) pushQ(sum,0,c+1);
            if(sum >= AF) pushQ(AF,sum-AF,c+1);
            if(sum <  BF) pushQ(0,sum,c+1);
            if(sum >= BF) pushQ(sum-BF,BF,c+1);
        }
    }

    return -1;
}


int main()
{
    cin >> AF >> BF >> RA >> RB; //AF: 물통 A의 용량, RA: 물통 A에 남겨야하는 물의 양
    cout << bfs() << endl;
    return 0;
}


//정올 3231 물탱크
#include <iostream>
#include <queue>
#define NN 1004
using namespace std;

struct Data {
    int y,x,h;
    bool operator<(const Data& b) {
        if(y != b.y) return y<b.y;
        if(x != b.x) return x<b.x;
        return h>b.h;
    }
};

int  N,M,H, sum=0;
int  s[NN][NN],g[NN][NN];
bool chk[NN][NN];

priority_queue<Data> q;
void Push(int y, int x, int h)
{
    if(chk[y][x] == 0) q.push({y,x,h});
}

void input()
{
    cin >> N >> M >> H;
    for(int y=1; y<=N+1; y++)for(int x=1; x<=M; x++)
    {
        cin >> g[y][x];
        if(g[y][x] == -1) g[y][x] = H;
    }
    for(int y=1; y<=N; y++)for(int x=1; x<=M+1; x++)
    {
        cin >> s[y][x];
        if(s[y][x] == -1) s[y][x] = H;
    }
}

void init()
{
    for(int y=1; y<=N; y++)
    {
        Push(y,1,s[y][1]);
        Push(y,M,s[y][M+1]);
        chk[y][0] = chk[y][M+1] = 1;
    }
    for(int x=1; x<=M; x++)
    {
        Push(1,x,g[1][x]);
        Push(N,x,g[N+1][x]);
        chk[0][x] = chk[N+1][x] = 1;
    }
}

void solve()
{
    int y,x,h;
    while(q.size())
    {
        Data d = q.top(); q.pop();
        y=d.y, x=d.x, h=d.h;

        if(chk[y][x]) continue;
        chk[y][x] = 1;

        sum += h;
        Push(y,x+1,max(h,s[y][x+1]));
        Push(y+1,x,max(h,g[y+1][x]));
        Push(y,x-1,max(h,s[y][x]));
        Push(y-1,x,max(h,g[y][x]));
    }
}

int main()
{
    Data a,b;

    input(); init();
    solve();
    cout << sum << endl;
    return 0;
}



//Swap 함수
#include <iostream>

using namespace std;

void Swap1(int* a, int* b) //call by address
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void Swap2(int &a, int &b) // call by reference
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}


int main()
{
    int x=10, y=20;  Swap2(x,y);
    cout << x << ' ' << y << endl;
    return 0;
}