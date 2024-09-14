#include <iostream>
// #include <math.h>
// #include <vector>
// #include <cstring>
using namespace std;

// 利用指数增长计算高次幂
int fast_power(int n, int power)
{
    int res = 1;

    while (power != 0)
    {
        if (power & 1)
            res *= n;
        n *= n;
        power >>= 1;
    }

    return res;
}

int main()
{
    printf("%d", fast_power(5, 3));
}