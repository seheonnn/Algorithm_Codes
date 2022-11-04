//vector
#include <iostream>

#include <vector>

using namespace std;



int main()

{

    vector<int> v;

    v.push_back(5);

    v.push_back(5);

    v.push_back(5);

    v.push_back(5);

    v.push_back(5);

    v.push_back(5);

    v.push_back(5);



    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)

    {

        cout << *i << ' ';

    }

    cout << '\n' << endl;



    //usually

    for (auto i = v.begin(); i != v.end(); i++)

    {

        cout << *i << ' ';

    }

    cout << '\n' << endl;



    //usually

    for (int k : v)

    {

        cout << k << ' ';

    }

    cout << '\n' << endl;





    //only vector 

    for (int i = 0; i < v.size(); i++)

    {

        cout << v[i] << ' ';

    }

    cout << '\n' << endl;





    return 0;

}