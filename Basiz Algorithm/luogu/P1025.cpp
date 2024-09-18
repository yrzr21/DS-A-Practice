#include <iostream>
using namespace std;

int ans;

// target = n - cursum
void divide(int target, int min, int nleft)
{
    if (target == 0 && nleft == 0) // valid
    {
        ans++;
        return;
    }
    if (target - nleft * min < 0 || (nleft == 0 && target > 0)) // invalid
        return;

    // 可以继续枚举
    
    for (int i = min; i <= target; i++)
        divide(target - i, i, nleft - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    divide(n,1,k);
    cout<<ans;
}
