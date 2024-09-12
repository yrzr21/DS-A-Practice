#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        // 对差值排序
        int res = 0, cnt1 = 0;
        vector<int> difference; // 以1为参照，取绝对值
        for (int i = 0; i < reward1.size() && cnt1 != k; i++)
            difference.push_back(reward1[i] - reward2[i]);
        sort(difference.begin(), difference.end());

        int result = 0;
        for (int i = 0; i < k; i++)
            result += difference[reward1.size() - i - 1];
        for (int i = 0; i < reward2.size(); i++)
            result += reward2[i];
        return result;
    }
};

int main()
{
}