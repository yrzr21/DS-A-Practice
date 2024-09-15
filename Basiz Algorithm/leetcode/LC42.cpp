#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// 一种超时的解法，每次计算一行的rain_cnt
// class Solution
// {
// public:
//     int rain_cnt = 0;
//     // vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//     void rain_1height(vector<int> &heights)
//     {
//         stack<int> s;
//         int tmp_cnt = 0;
//         for (int &height : heights)
//         {
//             if (s.empty() && height > 0)
//                 s.push(1);
//             else if (!s.empty() && height <= 0)
//                 tmp_cnt++;
//             else if (!s.empty() && height > 0)
//             {
//                 rain_cnt += tmp_cnt;
//                 tmp_cnt = 0;
//                 // 不用出栈，就当出栈再入栈了
//             }
//             height--;
//         }
//     }
//     int trap(vector<int> &height)
//     {
//         int max_height = -1;
//         for (int ht : height)
//             max_height = max(max_height, ht);
//         for (int i = 0; i < max_height; i++)
//             rain_1height(height);
//         return rain_cnt;
//     }
// };

// 一次计算一列
class Solution
{
public:
    int rain_cnt = 0;

    int trap(vector<int> &height)
    {
        stack<int> s; // index
        // vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        for (int i = 0; i < height.size(); i++)
        {
            // height[i] > s.top()

            while (!s.empty() && height[i] > height[s.top()])
            {
                int base = height[s.top()];
                s.pop();
                if (s.empty())
                    break;

                while (!s.empty() && height[s.top()] == base)
                    s.pop();
                if (s.empty())
                    break;

                int ht = min(height[s.top()], height[i]) - base;
                int width = i - s.top() - 1;
                rain_cnt += width * ht;
            }

            s.push(i);
        }

        return rain_cnt;
    }
};

int main()
{
    Solution s;
    // vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> v{4,2,0,3,2,5};
    int ans = s.trap(v);
    cout << ans << endl;
}
