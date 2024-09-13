#include <iostream>
using namespace std;

int L, M, N, D[50005];

int main()
{
    cin >> L >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> D[i];
    D[0] = 0;
    D[N + 1] = L; // 起点和终点

    int l = 0, r = L, mid; // 闭区间
    int ans;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int distance_cnt = 0, rock_cnt = 0;
        for (int i = 0; i <= N; i++) // 去除下一块石头.终点的情形可以与此合并，多去除一块肯定满足距离长度
        {
            distance_cnt = distance_cnt + D[i + 1] - D[i];
            if (distance_cnt < mid)
                rock_cnt++;
            else
                distance_cnt = 0;
        }

        if (rock_cnt > M)
            r = mid - 1;
        else // 相等也需要继续寻找
        {
            l = mid + 1;
            ans = mid;
        }
    }
    std::cout << ans;
    
}