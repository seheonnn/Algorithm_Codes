#include <stdio.h>
#include <algorithm>
//#include <stack>
//#include <queue>
#define N 10
using namespace std;//

struct CPoint
{
public://

    int x, y;

    CPoint() {}//
    CPoint(int a, int b) { x = a, y = b; }

    void Prt()
    {
        printf("x=%d.y=%d\n", x, y);
    }
};

class CRect
{
public:
    int left, top, right, bottom;

    CRect() {}
    CRect(int left, int b, int c, int d)
    {
        this->left = left, top = b, right = c, bottom = d;
    }

    int GetLeft()
    {
        return left;
    }

    void SetLeft(int k)
    {
        left = k;
    }

    void Prt()
    {
        printf("left=%d, top=%d, right = %d, bottom=%d\n", left, top, right, bottom);
    }

    CPoint topLeft()
    {
        return CPoint(left, top);
    }

    CPoint CenterCPoint()
    {
        return CPoint((left + right) / 2, (top + bottom) / 2);
    }

    CPoint BottomRight()
    {
        return CPoint(right, bottom);
    }

    int Width()
    {
        return right - left;
    }

    int Height()
    {
        return bottom - top;
    }

    int Area()
    {
        return Width() * Height();
    }

    void InflateCRect(int a, int b, int c, int d)
    {
        left -= a, top -= b, right += c, bottom += d;
    }

    void MoveToXY(int x, int y)
    {
        right = x + Width(), bottom = y + Height();
        left = x, top = y;
    }

    void OffsetCRect(int x, int y)
    {
        left += x, top += y, right += x, bottom += y;
    }
    void NormalizeCRect()
    {
        if (left > right) swap(left, right);
        if (top > bottom) std::swap(top, bottom);
    }

    int PtInCRect(CPoint p)
    {
        return p.x >= left && p.x < right&& p.y >= top && p.y < bottom;
    }

    CRect IntersectCRect(CRect k)
    {
        int l = max(left, k.left);
        int t = max(top, k.top);
        int r = min(right, k.right);
        int b = min(bottom, k.bottom);

        return CRect(l, t, r, b);
    }
};

struct Stack
{
private://

    int a[N], sp = 0;

public://
    Stack() {}//
    void push(int k)
    {
        a[sp++] = k;
    }
    int top()
    {
        return a[sp - 1];
    }
    void pop()
    {
        sp--;
    }
    int size()
    {
        return sp;
    }
};

class Queue
{
    int arr[N], fr = 0, rear = 0;
public:
    Queue() {}
    void push(int k)
    {
        arr[rear] = k;
        rear = (rear + 1) % N;
    }
    void pop()
    {
        fr = (fr + 1) % N;
    }
    int size()
    {
        return (rear - fr + N) % N;
    }
    int front()
    {
        return arr[fr];
    }
};


class Pentagon
{
public:
    Pentagon()
    {
        /*CPoint p;

        p.x = 10, p.y = 20;

        CRect r(10, 20, 30, 30), x = CRect(10, 10, 20, 20), h;

        x.Prt();

        printf("%d\n", x.Area());

        x.MoveToXY(0, 0);
        x.Prt();

        printf("%d\n\n", x.Area());*/

        //stack<int> s;
        Stack s;
        s.push(-5);
        s.push(20);
        s.push(6);
        s.push(1);
        s.push(-16);
        s.push(-10);
        s.push(15);
        s.push(9);
        s.push(0);
        s.push(7);
        printf("%d\n", s.size());
        while (s.size())
        {
            printf("%d,", s.top());
            s.pop();
        }
        printf("\n");


        //queue<int> q;
        Queue q;
        q.push(-5);
        q.push(20);
        q.push(6);
        q.push(1);
        q.push(-16);
        q.push(-10);
        q.push(15);
        q.push(9);
        q.push(0);
        q.pop();
        q.push(2);
        printf("%d\n", q.size());
        while (q.size())
        {
            printf("%d,", q.front());
            q.pop();
        }





        printf("\n");
    }
};

Pentagon a;

int main()

{


}