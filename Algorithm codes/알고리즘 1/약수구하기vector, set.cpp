// 벡터를 이용한 약수 구하기

#include <iostream>

#include <vector>

#include <math.h>

#include <algorithm>

using namespace std;



vector<int> v;



void factor(int n)

{

    int t = sqrt(n);

    for (int i = 1; i <= t; i++)

    {

        if (n % i == 0)  v.push_back(i), v.push_back(n / i);

    }

    if (t * t == n)  v.pop_back();

    sort(v.begin(), v.end());

}



int main()

{

    int n, s = 0, g = 1;



    cin >> n;

    factor(n);



    for (int k : v)

    {

        cout << k << " ";

        s += k;

        g *= k % 10;

    }



    cout << endl << v.size() << endl;

    cout << s << endl;

    cout << g;

}











//set을 이용한 약수 구하기

#include <iostream>

#include <set>

#include <math.h>

#include <algorithm>

using namespace std;



set<int> s;





void factor(int n)

{

    int t = sqrt(n);

    for (int i = 1; i <= t; i++)

    {

        if (n % i == 0)  s.insert(i), s.insert(n / i);

    }

}



int main()

{

    int n, h = 0, g = 1;

    cin >> n;

    factor(n);

    for (int k : s)

    {

        cout << k << " ";

        h += k;

        g *= k; g %= 10;

    }

    cout << endl << s.size() << endl;

    cout << h << endl;

    cout << g << endl;

}