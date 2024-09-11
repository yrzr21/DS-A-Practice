#include <iostream>
using namespace std;

int n, m;
int matrix[1001][1001], mark[1001][1001], sum[1001][1001];

int main()
{
    cin >> n >> m;
    int x1, y1, x2, y2;
    for (int i = 1; i <= m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        mark[x1][y1]++, mark[x1][y2 + 1]--, mark[x2 + 1][y1]--, mark[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = mark[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            cout << sum[i][j] << ' ';
        }
        cout << '\n';
    }
}