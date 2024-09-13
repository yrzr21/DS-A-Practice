#include <iostream>
#include <algorithm>
using namespace std;

long long cost(int hi, int hj)
{
    return (hi - hj) * (hi - hj);
}

bool compare(int x, int y)
{
    return x < y;
}

// 每次选高度差最大的。可以先排个序，每次在最大的和最小的间左右横跳
int main()
{
    int n, h[301]; // 0 3 5   6
    h[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    sort(h, h + n + 1, compare);
    // 0 n;n 1; 1 n-1; n-1 2; 2 n-2
    int curpos = 0, nextpos = n, downnext = 1, upnext = n;
    int final_pos = n % 2 == 0 ? n / 2 : n / 2 + 1;
    long long consume = 0;
    // while(downnext <= upnext)
    while(curpos != final_pos) // 这俩while都行。或者一个while跳俩，下小于上就行
    {
        nextpos = curpos > final_pos ? downnext++ : upnext--;
        consume += cost(h[curpos], h[nextpos]);
        curpos = nextpos;
    }
    cout << consume;
}