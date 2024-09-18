#include <iostream>
// #include <math.h>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// #include <string>
// #include <algorithm>
// #include <stack>
using namespace std;

int n, ans[11];
bool accessed[11];

void all_seq(int k)
{
    if (k > n)
    {
        for (int i = 1; i <= n; i++)
            cout << "    " << ans[i];
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (accessed[i])
            continue;
        accessed[i] = true;
        ans[k] = i;
        all_seq(k + 1);
        accessed[i] = false;
    }
}

int main()
{
    cin >> n;
    all_seq(1);
}
