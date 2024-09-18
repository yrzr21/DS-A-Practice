#include <iostream>
using namespace std;

long long res[21][21][21]; // 单调增

long long w(long long a, long long b, long long c);

long long result(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return result(20, 20, 20);

    if (res[a][b][c] == 0)
        res[a][b][c] = w(a, b, c);
    return res[a][b][c];
}

// 保证数据满足下述两种情形
long long w(long long a, long long b, long long c)
{
    if (a < b && b < c)
        return result(a, b, c - 1) + result(a, b - 1, c - 1) - result(a, b - 1, c);
    else
        return result(a - 1, b, c) + result(a - 1, b - 1, c) + result(a - 1, b, c - 1) - result(a - 1, b - 1, c - 1);
}

int main()
{
    long long a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result(a, b, c) << "\n";
    }
}
