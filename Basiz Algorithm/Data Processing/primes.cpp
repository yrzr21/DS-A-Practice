#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;

// O(n^2)
bool naive_isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// 一点优化: 大于数的一半的数一定不是数的约数
// O(n^2)
bool naive_isPrime_plus(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// 再次优化: 假设非质数，则两个因数一个必大于等于根号n，另一个小于等于根号n
// O(n^(3/2))
bool naive_isPrime_plus_plus(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// 合数必可被分解为小于他的质数积
void primes_ai(int n)
{
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        int isPrime = true;
        for (int prime : primes)
        {
            if (i % prime == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            primes.push_back(i);
    }

    // for (int prime : primes)
    //     cout << prime << " ";
}

// 每个合数都可以分解为小于它的唯一的质数组合.合数也可以被利用
const int maxn = 1e7;
bool isPrime[maxn];
void primes_euler(int n)
{
    if (n > maxn)
    {
        printf("n too large\n");
        return;
    }

    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = 0, isPrime[1] = 0;
    vector<int> primes;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i]) // 此时是质数的必为质数
            primes.push_back(i);

        for (int prime : primes)
        {
            int num = i * prime;
            if (num > n)
                break;
            isPrime[num] = false;
        }
    }

    for (int prime : primes)
        cout << prime << " ";
}

int main()
{
    // primes_ai(100);
    primes_euler(10);
}