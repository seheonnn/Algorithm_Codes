//우선순위 큐

#include <iostream>

#include <vector>



using namespace std;



class Priority_queue

{

   vector<int> v={0};



public:

   void push(int k)

   {

       v.push_back(k);

       for(int me = v.size() - 1, par = me/2 ; par >= 1 ; me = par, par = me/2)

       {

           if(v[me] <= v[par]) break;

           swap(v[me], v[par]);

       }

   }



   void pop()

   {

       v[1] = v.back(); v.pop_back();

       int sz = v.size() - 1;

       for(int me = 1, cld = 2 ; cld <= sz ; me = cld, cld = me*2)

       {

           if(cld+1<=sz && v[cld]<v[cld+1]) cld++;

           if(v[me] >= v[cld]) break;

           swap(v[me], v[cld]);

       }

   }



   int top()

   {

       return v[1];

   }



   int size()

   {

       return v.size() - 1;

   }



};



int main()

{

   Priority_queue q;



   q.push(-1);

   q.push(-8);

   q.push(-9);

   q.push(-7);

   q.push(-3);

   q.push(-4);

   q.push(-5);

   q.push(-6);



   cout << q.size()<< endl ;

   while(q.size())

   {

       cout << -q.top() << ' ';

       q.pop();

   }

}