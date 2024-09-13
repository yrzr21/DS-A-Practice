#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    { //
        int l = 0, colored = 0;
        for (int r = 0; r < k; r++) // 初始化
        {
            if (blocks[r] == 'W')
                colored += 1;
        }
        int black_cnt = k, min_colored = colored;

        for (int r = k; r < blocks.length(); r++)
        {
            // 涂黑blocks[r]
            if (blocks[r] == 'W')
                colored += 1;
            black_cnt++;

            if (black_cnt > k)
            {
                if (blocks[l++] == 'W')
                    colored--;
                black_cnt--;
            }

            if (colored < min_colored)
                min_colored = colored;
        }

        return min_colored;
    }
};

int main(int argc, char const *argv[])
{
    int target;
    // vector<int> nums = {10, 5, 2, 6};
    int res = (new Solution)->minimumRecolors("BWWWBB", 6);
    cout << res;
    return 0;
}