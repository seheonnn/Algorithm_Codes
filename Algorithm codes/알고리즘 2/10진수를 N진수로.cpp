//10진수를 N진수로

#include <iostream>

#include <algorithm>



using namespace std;



string n2x(int n, int x)

{

   string a;

   for(int r; n; n/=x)

   {

       r=n%x;

       if(r<10) a.push_back(r+'0');

       else a.push_back(r-10+'A');

   }

   reverse(a.begin(), a.end());

   return a;

}



int main()

{

   cout << n2x(36,16);

   return 0;

}