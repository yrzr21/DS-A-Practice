#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10001

/* 以下为 floyd 算法实现 */

int n;
int dis[MAXN][MAXN];

void floyd_warshell()
{
    // 对每对结点，考虑经过中转结点k是否是更短的路径
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) // 对于每对结点
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

////////////////////////////////////////////////////////////////////////////////////////

/* 以下为 dijkstra 算法实现 */

/* 链式前向星表示的图 */
struct edge
{
    int weight;
    int to;
};
vector<vector<edge>> v;

/* 一些 dijkstra 算法需要的数据结构 */
int dist[MAXN];      // 源点到点的最短距离
int pre[MAXN];       // 最短路径的前驱点
bool accessed[MAXN]; // 该点是否已纳入最短路径内

/* 比较器，堆顶为未纳入路径的最短点 */
struct vertex
{
    int v, distance;
};
struct vertex_compare
{
    bool operator()(const vertex &l, const vertex &r)
    {
        return l.distance > r.distance; // 小顶堆
    }
};

/* dijkstra 算法 */

void dijkstra(int s) // source node
{
    // 初始化s到其他点的最短距离
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;

    priority_queue<vertex, vector<vertex>, vertex_compare> q;
    q.push({s, 0});

    while (!q.empty())
    {
        struct vertex vtx = q.top();
        q.pop();
        if (vtx.distance > dist[vtx.v]) // 不是最新的顶点
            continue;
        accessed[vtx.v] = true;

        for (struct edge e : v[vtx.v]) // 更新邻接点距离并把合适的邻接点插入堆
        {
            if (accessed[e.to])
                continue;
            int distance = dist[vtx.v] + e.weight;
            if (distance < dist[e.to])
            {
                dist[e.to] = distance;
                pre[e.to] = vtx.v;        // 前驱点更新
                q.push({e.to, distance}); // 可能会重复插入，利用if判断是否是最新的顶点
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////

/* 以下为 Bellman-ford 算法实现 */

struct Edge
{
    int weight;
    int to;
    int from;
};
vector<Edge> edges;

int d[MAXN]; // 最短路径长度
int p[MAXN]; // 最短路径的前驱点

void Bellman_Ford(int s)
{
    for (int i = 1; i <= n; i++) // 初始化
    {
        p[i] = -1;
        d[i] = INT_MAX;
    }

    for (int i = 1; i <= n - 1; i++) // 最长经过n-1条边到达一个顶点，故最多松弛V-1次
    {
        bool relaxed = false;
        for (struct Edge e : edges)
        {
            if (d[e.from] + e.weight < d[e.to])
            {
                d[e.to] = d[e.from] + e.weight;
                p[e.to] = e.from;
                relaxed = true;
            }
        }
        if (!relaxed)
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

/* 以下为 SPFA 算法实现 */

// 这个实现还没有完成

// struct edge
// {
//     int weight;
//     int to;
// };
// vector<vector<edge>> v;

int dst[MAXN];

void spfa(int s)
{
    for (int i = 1; i <= n; i++)
        dst[i] = INT_MAX;

    queue<int> relaxed_q;
    relaxed_q.push(s);

    while (!relaxed_q.empty())
    {
        int last_relaxed_v = relaxed_q.front();
        relaxed_q.pop();

        for (struct edge e : v[last_relaxed_v])
        {
            if (e.weight + dst[last_relaxed_v] < dst[e.to])
            {
                dst[e.to] = e.weight + dst[last_relaxed_v];
                relaxed_q.push(e.to);
            }
        }
    }
}
