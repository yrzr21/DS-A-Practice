#include <iostream>
using namespace std;

int n, target_x, target_y;
int x[110001], y[110001], x_len[110001], y_len[110001];

bool in_area(int i)
{
    return target_x >= x[i] && target_x < x[i] + x_len[i] && target_y >= y[i] && target_y < y[i] + y_len[i];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> x_len[i] >> y_len[i];
    cin >> target_x >> target_y;

    int res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (in_area(i))
        {
            res = i;
            break;
        }
    }
    cout << res + 1;
}