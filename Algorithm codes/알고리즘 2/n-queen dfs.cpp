
//창의적 알고리즘 n-queen dfs
#include <iostream>
#include <map>
using namespace std;
struct point {int y,x;};

int n, cnt = 0;
map<int,int> a,b,c; //Map은 음수의 index가 가능, 배열로 할 시 음수의 index가 불가능하기 때문에 +n해야함

void dfs(int y)
{
    if(y == n)
    {
        cnt++;
        return;
    }
    for(int x=0; x<n; x++)
    {
        if(a[x] == 0 && b[x+y] == 0 && c[x-y] == 0)
        {
            a[x] = b[x+y] = c[x-y] = 1;
            dfs(y+1);
            a[x] = b[x+y] = c[x-y] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << cnt;
}