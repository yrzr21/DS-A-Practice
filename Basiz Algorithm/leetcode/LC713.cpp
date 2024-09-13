#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;

        int cnt = 0, l = 0, product = 1;
        for (int r = 0; r < nums.size(); r++)
        {
            product *= nums[r];
            while (product >= k && l <= r)
            {
                product /= nums[l];
                l++;
            }
            cnt = cnt + r - l + 1; // 以左区间端点为起始，有这么多种可能的答案
        }

        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    int target;
    vector<int> nums = {10,5,2,6};
    int res = (new Solution)->numSubarrayProductLessThanK(nums, 100);
    cout << res;
    return 0;
}