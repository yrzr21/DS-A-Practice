#include <iostream>
using namespace std;

int n, na, nb;
int a_circle[205], b_circle[205];
int a_score, b_score;

int result[5][5] = {
    {0, -1, 1, 1, -1},
    {1, 0, -1, 1, -1},
    {-1, 1, 0, -1, 1},
    {-1, -1, 1, 0, 1},
    {1, 1, -1, -1, 0}};

int next_a()
{
    static int index = -1;
    index = (index + 1) % na;
    return a_circle[index];
}

int next_b()
{
    static int index = -1;
    index = (index + 1) % nb;
    return b_circle[index];
}

int one_result(int a, int b)
{
    return result[a][b];
}

int main()
{
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
        cin >> a_circle[i];
    for (int i = 0; i < nb; i++)
        cin >> b_circle[i];
    a_circle[na] = b_circle[nb] = -1; // end

    for (int i = 0; i < n; i++)
    {
        int result = one_result(next_a(), next_b());
        if (result > 0)
            a_score++;
        else if(result < 0)
            b_score++;
    }
    cout << a_score << " " << b_score;
}