/*

//두 용액

#include <iostream>

#include <algorithm>

#include <vector>

#include <math.h>

using namespace std;



int main()

{

    int n;  cin >> n;



    vector<int> v(n);



    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());





    int msum = 987654321, x, y;

    for (int s=0, e=n-1, sum; s<e;)

    {

        sum = v[s] + v[e];

        if(msum > abs(sum)) { x = v[s], y = v[e], msum = abs(sum); }

        if(sum < 0) s++;

        else if(sum > 0) e--;

        else break;

    }

    cout << x << ' ' << y << endl;

}

*/



//세 용액

#include <iostream>

#include <algorithm>

#include <vector>

#include <math.h>

using namespace std;



int main()

{

    int n;  cin >> n;



    vector<int> v(n);



    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());





    int msum = 987654321, x, y, z;

    for (int s = 0, e = n - 1, sum; s < e;)

    {

        sum = v[s] + v[e];

        auto p = upper_bound(v.begin(), v.end(), sum) - v.begin();//auto = vector<int>::iterator

        auto q = p - 1;



        if (p <= s || p > e)

            continue;



        else

        {

            if (p == e)  sum += v[q];

            else

            {

                if (abs(sum + v[p]) < abs(sum + v[q]))  sum += v[p], z = v[p];

                else sum += v[q], z = v[q];

            }

        }



        if (msum > abs(sum)) { x = v[s], y = v[e], msum = sum; }

        if (sum < 0) s++;

        else if (sum > 0) e--;

        else break;



    }

    cout << x << " " << z << " " << y << endl;

}