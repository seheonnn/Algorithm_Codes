

//Å« ¼öÀÇ »¬¼À

#include <iostream>

#include <string>

#include <algorithm>

using namespace std;



int main()

{



    string a, b, f;   cin >> a >> b;

    if (a.size() < b.size() || (a.size() == b.size() && a < b))

    {

        f = "-";

        swap(a, b);

    }



    reverse(a.begin(), a.end());

    reverse(b.begin(), b.end());



    vector<int> x(a.size()), y(b.size());



    for (int i = 0, e = a.size(); i < e; i++) x[i] = a[i] - '0';

    for (int i = 0, e = b.size(); i < e; i++) y[i] = b[i] - '0';



    for (int i = 0, e = y.size(); i < e; i++) x[i] -= y[i];

    for (int i = 0, e = x.size(); i < e; i++)

    {

        if (x[i] < 0) x[i + 1]--, x[i] += 10;

    }

    while (x.size() > 1 && x.back() == 0) x.pop_back();



    cout << f;

    for (int i = x.size() - 1; i >= 0; i--)

    {

        cout << x[i];

    }

}









//Å« ¼öÀÇ °ö¼À



#include <iostream>

#include <string>

#include <algorithm>

#include <math.h>

using namespace std;



int main()

{

    string a, b;  cin >> a >> b;



    reverse(a.begin(), a.end());

    reverse(b.begin(), b.end());



    vector<int> x(a.size()), y(b.size()), z(a.size() + b.size());



    for (int i = 0, e = a.size(); i < e; i++) x[i] = a[i] - '0';

    for (int i = 0, e = b.size(); i < e; i++) y[i] = b[i] - '0';

    for (int i = 0, e = y.size(); i < e; i++)

    {

        for (int k = 0, e = x.size(); k < e; k++)

        {

            z[i + k] += y[i] * x[k];

        }

    }

    for (int i = 0, e = z.size(); i < e; i++)

    {

        int m = z[i] / 10;

        if (m > 0)

        {

            if (i + 1 < e) z[i + 1] += m;

            else        z.push_back(m), e++;

            z[i] %= 10;

        }

    }

    if (z[z.size() - 1] == 0)  z.pop_back();

    for (int i = z.size() - 1; i >= 0; i--)

        cout << z[i];

}