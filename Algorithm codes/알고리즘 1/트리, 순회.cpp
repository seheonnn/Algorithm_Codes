////tree
//#include <iostream>
//
//#include <vector>
//
//using namespace std;
//
//class Node
//
//{
//
//public:
//
//    Node* par;
//
//    vector<Node*> cld;
//
//    int num, dep;
//
//
//
//};
//
//
//
//Node nd[10000], * root;
//
//int n, x, y;
//
//
//
//Node* find_root(Node* p)
//
//{
//
//    if (p->par == NULL) return p;
//
//    return find_root(p->par);
//
//}
//
//
//
//void get_depth(Node* p)
//
//{
//
//    for (auto q : p->cld)
//
//    {
//
//        q->dep = p->dep + 1;
//
//        get_depth(q);
//
//    }
//
//}
//
//
//
//
//
//int main()
//
//{
//
//    cin >> n;
//
//
//
//    for (int i = 0; i <= n; i++) nd[i].num = i;
//
//
//
//    for (int i = 1, a, b; i < n; i++)
//
//    {
//
//        cin >> a >> b;
//
//        nd[a].cld.push_back(&nd[b]);
//
//        nd[b].par = &nd[a];
//
//    }
//
//    cin >> x >> y;
//
//
//
//
//
//    root = find_root(&nd[x]);
//
//    get_depth(root);
//
//
//
//    Node* u = &nd[x], * v = &nd[y];
//
//
//
//    if (u->dep < v->dep) swap(u, v);
//
//    while (u->dep > v->dep) u = u->par;
//
//    while (u != v) u = u->par, v = v->par;
//
//
//
//    cout << u->num;
//}


//
////순회
//#include <iostream>
//
//
//
//using namespace std;
//
//
//
//int nd[100000];
//
//
//
//void preorder(int idx)//preorder로 입력
//
//{
//
//    cin >> nd[idx];
//
//    if (nd[idx] == -1) return;
//
//    preorder(idx * 2);
//
//    preorder(idx * 2 + 1);
//
//}
//
//
//
//void inorder(int idx)
//
//{
//
//    if (nd[idx] == -1) return;
//
//    inorder(idx * 2);
//
//    cout << nd[idx] << ' ';
//
//    inorder(idx * 2 + 1);
//
//}
//
//
//
//void postorder(int idx)
//
//{
//
//    if (nd[idx] == -1) return;
//
//    postorder(idx * 2);
//
//    postorder(idx * 2 + 1);
//
//    cout << nd[idx] << ' ';
//
//}
//
//
//
//
//
//int main()
//
//{
//
//    preorder(1);
//
//    postorder(1);
//
//    return 0;
//
//}


//
//
////순회
//#include <iostream>
//#include <map>
//using namespace std;
//map<char, int> m;
//char nd[100000];
//string a, b;
//void preorder(int idx, char ch)
//{
//    if (nd[idx] == 0)
//    {
//        nd[idx] = ch;
//        return;
//    }
//    if (m[ch] < m[nd[idx]])
//        preorder(idx * 2, ch);
//    else
//        preorder(idx * 2 + 1, ch);
//}
//
//void postorder(int idx)
//{
//    if (nd[idx] == 0) return;
//    postorder(idx * 2);
//    postorder(idx * 2 + 1);
//    cout << nd[idx];
//}
//
//int main()
//{
//    cin >> a >> b;
//    for (int i = 0; i < a.size(); i++) m[a[i]] = i + 1;
//
//    //  for(pair<char,int> p : m)
//    //        cout << p.first << ' ' << p.second << endl;
//    for (int i = 0; i < b.size(); i++) preorder(1, b[i]);
//
//    postorder(1);
//}



//
//
////pre, in, postorder
//
//#include <iostream>
//
//
//
//using namespace std;
//
//
//
//int arr[1000];
//
//
//
//void preorder(int n)
//
//{
//
//    cin >> arr[n];
//
//    if(arr[n]==-1) return;
//
//    preorder(2*n);
//
//    preorder(2*n+1);
//
//}
//
//
//
//void postorder(int n)
//
//{
//
//    if(arr[n]==-1) return;
//
//    postorder(2*n);
//
//    postorder(2*n+1);
//
//    cout << arr[n] << " ";
//
//}
//
//
//
//int main()
//
//{
//
//    preorder(1);
//
//    postorder(1);
//
//}


//tree

#include <iostream>

#include <algorithm>



using namespace std;



class Node

{

public: Node* par, * lc, * rc;

      int num, dep;

};



Node nd[1010], * root = &nd[1];



int colcnt = 0;

int lmin[100], rmax[100];



void getDepth(Node* p, int dep)

{

    p->dep = dep;

    if (p->lc != NULL) getDepth(p->lc, dep + 1);



    {

        colcnt++;

        lmin[dep] = min(lmin[dep], colcnt);

        rmax[dep] = max(rmax[dep], colcnt);

    }



    if (p->rc != NULL) getDepth(p->rc, dep + 1);

}



int main()

{

    int n;

    cin >> n;

    fill(lmin, lmin + n, 1000);

    for (int i = 1, x, y, z; i <= n; i++)

    {

        nd[i].num = i;

        cin >> x >> y >> z;

        if (y != -1) nd[y].par = &nd[x], nd[x].lc = &nd[y];

        if (z != -1) nd[z].par = &nd[x], nd[x].rc = &nd[z];

    }

    cout <<



}