#include <vector>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max_pile = 0;
        for (int pile : piles)
            max_pile = max(max_pile, pile);
        int minK = max_pile;

        int l = 1, r = max_pile, mid;
        while (l <= r)
        {
            mid = (l + r) / 2; // 一次吃这么多
            int hours = 0;
            for (int pile : piles)
            {
                hours += pile / mid;
                if(pile % mid != 0)
                    hours++;
            }
            if(hours > h) // 吃少了
                l = mid + 1;
            else // 可以再吃少点
            {
                minK = mid;
                r = mid - 1;
            }
        }
        return minK;
    }
};

int main()
{
}