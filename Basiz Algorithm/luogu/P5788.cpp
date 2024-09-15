#include <iostream>
// #include <math.h>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// #include <string>
// #include <algorithm>
#include <stack>
using namespace std;

int n;

// struct node
// {
//     int data;
//     int fi;
// };

// node a[3000002];
int a[3000002], ans[3000002];

int main()
{
    // stack<node*> s;
    // cin >> n;
    // int x;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> a[i].data;
    //     while (!s.empty() && a[i].data > s.top()->data)
    //     {
    //         s.top()->fi = i;
    //         s.pop();
    //     }
    //     s.push(&a[i]);
    // }
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            ans[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    // for (int i = 1; i <= n; i++)
    //     cout << a[i].fi << " ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
