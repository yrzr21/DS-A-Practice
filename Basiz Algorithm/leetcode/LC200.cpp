
#include <vector>

using namespace std;
class Solution
{
public:
    void markland(int i, int j, vector<vector<char>> &grid)
    {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1')
            markland(i - 1, j, grid);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1')
            markland(i + 1, j, grid);
        if (j > 0 && grid[i][j - 1] == '1')
            markland(i, j - 1, grid);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
            markland(i, j + 1, grid);
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    markland(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main()
{
}
