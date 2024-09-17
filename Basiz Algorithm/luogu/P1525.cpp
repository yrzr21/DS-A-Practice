#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 20001

struct violence
{
    int a, b, c;
} v[MAXN];

bool comp(struct violence &v1, struct violence &v2)
{
    return v1.c > v2.c;
}

struct jail
{
    int vio;            // 最大violence
    bool in_jail[MAXN]; // 已在jail中的不考虑
} j[2];

bool in_jail(int jno, int pplno)
{
    return j[jno].in_jail[pplno];
}

void go2jail(int jno, int pplno, int vio)
{
    j[jno].in_jail[pplno] = true;
    j[jno].vio = max(j[jno].vio, vio);
}

// 目的：最大冲突最小化，两个监狱都有冲突时，选较小的
// 未完成
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> v[i].a >> v[i].b >> v[i].c;
    sort(&v[0], &v[M], comp);

    for (int i = 0; i < M; i++)
    {
        int a = v[i].a, b = v[i].b, c = v[i].c;
        if (in_jail(0, a))
        {
            if (in_jail(1, b) || in_jail(0, b))
                continue;
            else
                go2jail(1, b, c); // 此时的vio一定比b和任何人的冲突大
        }
        else if (in_jail(1, a))
        {
            if (in_jail(1, b) || in_jail(0, b))
                continue;
            else
                go2jail(0, b, c); // 此时的vio一定比b和任何人的冲突大
        }
        else if (in_jail(0, b)) // a未分配
        {
            if (in_jail(1, a) || in_jail(0, a))
                continue;
            else
                go2jail(1, a, c); // 此时的vio一定比b和任何人的冲突大
        }
        else if (in_jail(1, b))
        {
            if (in_jail(1, a) || in_jail(0, a))
                continue;
            else
                go2jail(0, a, c); // 此时的vio一定比b和任何人的冲突大
        }
        else // 均未分配
        {
            go2jail(0,a,c);
            go2jail(1,b,c);
        }

        if (j[0].vio != 0 && j[1].vio != 0)
            break;
    }

    cout << max(j[0].vio, j[1].vio);
}