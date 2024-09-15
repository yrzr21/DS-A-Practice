#include <iostream>
// #include <math.h>
#include <vector>
// #include <cstring>
// #include <cstdio>
// #include <string>
// #include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    // 1>0，2<0时才会比较
    int compare(int asteroid1, int asteroid2)
    {
        if (abs(asteroid1) == abs(asteroid2))
            return 0;
        else
            return asteroid1 + asteroid2;
    }

    // 栈空、栈尾向左移动、二者同向向右移动均不发生碰撞
    bool is_nocollision(int asteroid)
    {
        return s.empty() || s.back() < 0 || (s.back() > 0 && asteroid > 0);
    }

    vector<int> s;
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int res;
        for (int asteroid : asteroids)
        {
            while (!is_nocollision(asteroid) && (res = compare(s.back(), asteroid)) < 0)
                s.pop_back();

            if (is_nocollision(asteroid))
                s.push_back(asteroid);
            else if (res == 0)
                s.pop_back();
            // res > 0 不用做任何操作
        }

        return s;
    }
};

int main()
{
    vector<int> v{-2, -2, 1, -2};
    Solution s;
    s.asteroidCollision(v);
}
