
#include <vector>

using namespace std;
class Solution
{
public:

    // 标记ij的周边陆地
    void markland(int i, int j, vector<vector<char>> &grid)
    {
        if (i > 0 && grid[i - 1][j] == '1' )
        {
            grid[i - 1][j] = '0';
            markland(i - 1, j, grid);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == '1' )
        {
            grid[i + 1][j] = '0';
            markland(i + 1, j, grid);
        }
        if (j > 0 && grid[i][j - 1] == '1' )
        {
            grid[i][j - 1] = '0';
            markland(i, j - 1, grid);
        }
        if (j + 1 < grid.size() && grid[i][j + 1] == '1' )
        {
            grid[i][j + 1] = '0';
            markland(i, j + 1, grid);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {


        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == '1' && !marked[i][j])
                {
                    marked[i][j] = '0';
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
    vector<vector<int>> v = {
        ['1', '1', '1', '1', '0'],
        [ '1', '1', '0', '1', '0' ],
        [ '1', '1', '0', '0', '0' ],
        [ '0', '0', '0', '0', '0' ]};

    Solution s;
}
