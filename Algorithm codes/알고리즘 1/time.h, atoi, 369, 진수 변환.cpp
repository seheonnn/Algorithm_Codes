/*

//time.h 라이브러리

#include <iostream>

#include <time.h>

using namespace std;



int main()

{

    time_t now = time(0);

    struct tm* a = localtime(&now);

    cout << a->tm_year + 1900 << endl; //1900년부터 시작

    cout << a->tm_mon + 1 << endl; //0부터 시작, 1씩 더하기

    cout << a->tm_mday << endl;

    cout << a->tm_hour << endl;

    cout << a->tm_min << endl;

    cout << a->tm_sec << endl;



    struct tm b;

    b.tm_year = 100;

    b.tm_mon = 10;

    b.tm_mday = 22;

    b.tm_hour = 17;

    b.tm_min = 0;

    b.tm_sec = 0;

    time_t birth = mktime(&b);



    time_t myLife = now-birth;

    a = localtime(&myLife);



    cout << endl;

    cout << a->tm_year - 70 << endl; //1970년부터 시작

    cout << a->tm_mon + 1 << endl;

    cout << a->tm_mday << endl;

    cout << a->tm_hour << endl;

    cout << a->tm_min << endl;

    cout << a->tm_sec << endl;

}



*/



#include <iostream>



using namespace std;



int strlen(char* str)

{

    int c = 0;

    while (*str++) c++;

    return c;

}



int atoi(char* str)

{

    int r = 0;

    for (int i = 0; str[i]; i++)

    {

        r = r * 10 + (str[i] - '0');

    }

    return r;

}

//369게임

int cnt369(int n)

{

    int c = 0;

    for (; n; n /= 10)

    {

        if (n % 10 == 3 || n % 10 == 6 || n % 10 == 9) c++;

    }

    return c;

}

//n을 k진수로

#include <algorithm>

string i2bx(int n, int k)

{

    string s;

    for (int r; n; n /= k)

    {

        r = n % k;

        if (r < 10) s.push_back(r + '0');

        else       s.push_back(r - 10 + 'A');

    }

    reverse(s.begin(), s.end());

    return s;

}



int main()

{

    char str[100];

    int r;

    cin >> str;

    r = atoi(str);

    cout << i2bx(r, 2);

}