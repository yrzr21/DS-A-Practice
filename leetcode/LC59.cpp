// #include <iostream>
// using namespace std;

// int main()
// {

// }

// 正方形内生产螺旋矩阵
// 一次做完一行/列
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // [row][col]指向下一个要赋值的元素
        // lrtb分别表示边界，为闭区间
        vector<vector<int>> m(n, vector<int>(n));
        int l = 0, r = n - 1, t = 1, b = n - 1;
        int cnt = 1, row = 0, col = 0, target = n * n;
        while (cnt <= target)
        {
            while (cnt <= target && col <= r)
                m[row][col++] = cnt++;
            col = r;
            row++;

            while (cnt <= target && row <= b)
                m[row++][col] = cnt++;
            row = b;
            col--;

            while (cnt <= target && col >= l)
                m[row][col--] = cnt++;
            col = l;
            row--;

            while (cnt <= target && row >= t)
                m[row--][col] = cnt++;
            row = t;
            col++;

            r--, b--, l++, t++;
        }
        return m;
    }
};
