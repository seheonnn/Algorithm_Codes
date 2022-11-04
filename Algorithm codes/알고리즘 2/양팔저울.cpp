 

//정올 양팔저울

#include <iostream>

#include <vector>

#include <set>

using namespace std;

 

vector<int> v;

set<int,greater<int>> num;

int k, s = 0;

 

void dfs(int i, int sum)

{

    if(i == k)

    {

        if(sum > 0) num.insert(sum);

        return;

    }

    dfs(i+1,sum);

    dfs(i+1,sum+v[i]);

    dfs(i+1,sum-v[i]);

}

 

int main()

{

    cin >> k;

    v.resize(k);

 

    for(int i = 0; i < k; i++)   cin >> v[i];

    dfs(0,0);

    cout << *num.begin()-num.size();

}