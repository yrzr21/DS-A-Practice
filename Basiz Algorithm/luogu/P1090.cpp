#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> q;

// 每次选最小的数移动
int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    long long consume = 0;
    while (q.size() != 1)
    {
        int x, y, cost;
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        cost = (x + y);
        q.push(cost);
        consume += cost;
    }
    cout << consume;
}