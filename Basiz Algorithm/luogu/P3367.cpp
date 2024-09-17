#include <iostream>
// #include <math.h>
// #include <vector>
// #include <cstring>
// #include <cstdio>
// #include <string>
// #include <algorithm>
// #include <stack>
using namespace std;

int N, M;

struct node
{
    struct node *root;
} nodes[10005];


struct node* find_root(struct node* n)
{
    if(n == n->root)
        return n;

    n->root = find_root(n->root); // 路径压缩
    return n->root;
}

void merge(struct node *n1, struct node *n2) // n2合并到n1
{
    // n1->root = find_root(n2)或n1->root = n2不行，可能会出现分叉，即一个并查集有两个根
    // 又或者丢失一些结点。必须是两个并查集的根合并
    find_root(n1)->root = find_root(n2);
}

void is_root_same(struct node *n1, struct node *n2)
{
    if (find_root(n1) == find_root(n2))
        cout << "Y\n";
    else
        cout << "N\n";
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) // 初始化并查集
        nodes[i].root = &nodes[i]; // root

    for (int i = 0; i < M; i++)
    {
        int x, y, op;
        cin >> op >> x >> y;
        if (op == 1)
            merge(&nodes[x], &nodes[y]);
        else
            is_root_same(&nodes[x], &nodes[y]);
    }
}
