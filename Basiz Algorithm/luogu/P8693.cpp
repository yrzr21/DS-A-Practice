#include <iostream>
using namespace std;
#define MAXN 301

int n, k;
char map[MAXN][MAXN];
int time[MAXN][MAXN];

int getfat(int time)
{
    static int fat[3] = {2, 1, 0};
    if (time < k)
        return fat[0];
    else if (time < 2 * k)
        return fat[1];
    else
        return fat[2];
}

bool reach(int x, int y)
{
    return x == n - 2 && y == n - 2;
}

bool movable(int x, int y, int fat)
{
    return x - fat > 0 && x + fat <= n && y - fat > 0 && y + fat <= n;
}

int mv(int x, int y, int time, char direction)
{
    int fat = getfat(time);


    return time;
}

// 未完成
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin.getline((char *)map[i], n);

    int x = 3, y = 3, time = 0;
    while (!reach(x, y))
    {
        int fat = getfat(time);


        time++;
    }
    cout << time;
}
