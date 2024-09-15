#include <iostream>
// #include <math.h>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// #include <string>
// #include <algorithm>
#include <stack>
using namespace std;

int in_seq[100000], out_seq[100000];

bool is_correct(int n) // size
{
    int i = 0, o = 0; // index
    stack<int> s;

    while (i != n)
    {
        s.push(in_seq[i++]);
        while (!s.empty() && s.top() == out_seq[o])
        {
            s.pop();
            o++;
        }
    }

    return s.empty() ? true : false;
}

int main()
{
    int q, n;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> in_seq[j];
        for (int j = 0; j < n; j++)
            cin >> out_seq[j];

        if (is_correct(n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
