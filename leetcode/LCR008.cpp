#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int l = 0, sum = 0, length = nums.size() + 1;
        // lr闭区间
        for (int r = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (sum >= target) // 这里递减左边
            {
                length = r - l + 1 < length ? r - l + 1 : length;
                sum -= nums[l];
                l++;
            }
        }

        return length == nums.size() + 1 ? 0 : length;
    }
};

int main(int argc, char const *argv[])
{
    int target;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int res = (new Solution)->minSubArrayLen(7, nums);
    cout << res;
    return 0;
}
