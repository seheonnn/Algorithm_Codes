////창의적 알고리즘 n-queen dfs

//#include <iostream>

//#include <map>

//using namespace std;

//struct point {int y,x;};

//

//int n, cnt = 0;

//map<int,int> a,b,c; //Map은 음수의 index가 가능, 배열로 할 시 음수의 index가 불가능하기 때문에 +해야함

//

//void dfs(int y)

//{

//    if(y == n)

//    {

//        cnt++;

//        return;

//    }

//    for(int x=0; x<n; x++)

//    {

//        if(a[x] == 0 && b[x+y] == 0 && c[x-y] == 0)

//        {

//            a[x] = b[x+y] = c[x-y] = 1;

//            dfs(y+1);

//            a[x] = b[x+y] = c[x-y] = 0;

//        }

//    }

//}

//

//int main()

//{

//    cin >> n;

//    dfs(0);

//    cout << cnt;

//}

 

 

//창의적 알고리즘 선물 dfs

#include <iostream>

#include <vector>

#include <algorithm>

 

using namespace std;

 

vector<int> g;

 

int n, A, B, C, mmm=987654321;

 

void dfs(int no, int a, int b, int c)

{

    if(no == n)

    {

        if((a>=b && b>=c) && a-c < mmm)

        {

            mmm = a-c;

            A=a, B=b, C=c;

        }

        return;

    }

 

    dfs(no+1, a+g[no], b, c);

    dfs(no+1, a, b+g[no], c);

    dfs(no+1, a, b, c+g[no]);

}

 

int main()

{

    cin >> n;

    g.resize(n);//벡터는 resize해야 []사용 가능 or push_back() 사용해야함

    for(int i=0; i<n; i++) {

        cin >> g[i];

    }

    sort(g.begin(), g.end());

    dfs(0,0,0,0);

    cout << A << " " << B << " " << C;

}