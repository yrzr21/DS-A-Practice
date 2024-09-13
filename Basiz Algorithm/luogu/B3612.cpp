#include <iostream>
using namespace std;

int n, m;
int a[100002], sum[100002];
int l, r;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];    
        sum[i] = a[i] + sum[i - 1];
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n';
    }
    

}