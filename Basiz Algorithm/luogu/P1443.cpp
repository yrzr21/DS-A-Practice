#include <iostream>
#include <queue>
using namespace std;
#define MAXN 401

int n, m;
int map[MAXN][MAXN];
// 2 * 4 种可能
int stepx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int stepy[8] = {1, -1, -2, 2, -2, 2, 1, -1};

bool accessible(int i, int j)
{
    // index 有效且没访问过
    return i > 0 && i <= n && j > 0 && j <= m && map[i][j] == -1;
}

struct node
{
    int x, y;
};

void push_around(queue<node> &q, int x, int y)
{
    int step = map[x][y];
    for (int k = 0; k < 8; k++)
    {
        int ci = x + stepx[k], cj = y + stepy[k];
        if (!accessible(ci, cj))
            continue;
        q.push({ci, cj});
        map[ci][cj] = step + 1;
    }
}

int main()
{
    int x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            map[i][j] = -1;

    queue<node> q;
    q.push({x, y});

    map[x][y] = 0;

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        push_around(q, x, y);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << map[i][j] << '\t';
        cout << '\n';
    }
}
