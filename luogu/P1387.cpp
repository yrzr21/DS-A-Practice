#include <iostream>
using namespace std;

int n, m;
int matrix[101][101], sum[101][101];

int main()
{
    // input
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
        }
    }

    // 计算
    for (int l = min(n, m) - 1; l >= 0; l--)
    {
        // i,j 为正方形左上角元素，边长为l+1
        for (int i = 1; i + l <= n; i++)
        {
            for (int j = 1; j + l <= m; j++)
            {
                int cnt = sum[i + l][j + l] - sum[i - 1][j + l] - sum[i + l][j - 1] + sum[i - 1][j - 1];
                if (cnt == (l + 1) * (l + 1))
                {
                    cout << l + 1;
                    return 0;
                }
            }
        }
    }
    // 没有任何1
    cout << 0;
    return 0;
}