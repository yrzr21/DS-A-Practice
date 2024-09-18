// 链式前向星

#define MAXEDGE 100005
#define MAXHEAD 1002

struct node
{
    int to;   // head index
    int next; // edge index
    int weight;
} edges[MAXEDGE];

int next_edge; // 下一个可分配的 edge

int head[MAXHEAD]; // 元素为 edge indx

void insert(int hd, int to, int n, int w)
{
    edges[next_edge].to = to;
    edges[next_edge].next = head[hd];
    edges[next_edge].weight = w;
    head[hd] = next_edge++;

    // 无向图需要另外再插一次
}



