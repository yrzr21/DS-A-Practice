#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMiddleMax(int l, int r, int m, vector<int> &v)
    {
        int l_max = INT_MIN, cnt = 0;
        for (int i = m; i >= l; i--)
        {
            cnt += v[i];
            if (cnt > l_max)
                l_max = cnt;
        }
        int r_max = INT_MIN, rcnt = 0;
        for (int i = m + 1; i <= r; i++)
        {
            rcnt += v[i];
            if (rcnt > r_max)
                r_max = rcnt;
        }
        return l_max + r_max;
    }

    int findMax(int l, int r, vector<int> &v)
    {
        if (l > r)
            return -100000;
        if (l == r)
            return v[l];

        int mid = (l + r) / 2;
        int resl = findMax(l, mid, v);
        int resr = findMax(mid + 1, r, v);
        int resm = findMiddleMax(l, r, mid, v);
        return max(max(resl, resr), resm);
    }

    int maxSubArray(vector<int> &nums)
    {
        return findMax(0, nums.size() - 1, nums); // 闭区间
    }
};

int main()
{
}