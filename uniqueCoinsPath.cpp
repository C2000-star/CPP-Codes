#include <iostream>
#include <vector>
#define M 5
#define N 5
using namespace std;
vector<vector<int>> getPath(int dp[][N], int x, int y, vector<vector<int>> &path)
{
    if (x == 0 && y == 0)
    {
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        path.push_back(temp);
        return path;
    }
    else if (x == 0)
    {
        path = getPath(dp, x, y - 1, path);
    }
    else if (y == 0)
    {
        path = getPath(dp, x - 1, y, path);
    }
    else
    {
        if (dp[x - 1][y] > dp[x][y - 1])
            path = getPath(dp, x - 1, y, path);
        else
            path = getPath(dp, x, y - 1, path);
    }
    vector<int> temp;
    temp.push_back(x);
    temp.push_back(y);
    path.push_back(temp);
    return path;
}
int uniquePaths(int grid[][4], int x, int y)
{
    vector<vector<int>> path;
    int dp[M][N];
    dp[0][0] = grid[0][0];

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            dp[i][j] = grid[i][j];
            if (i > 0 && j > 0)
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
            else if (i > 0)
                dp[i][j] += dp[i - 1][j];
            else if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    path = getPath(dp, x, y, path);
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << "(" << path[i][0] << "," << path[i][1] << ")";
        if (i != path.size() - 1)
            std::cout << "->";
    }
    return 0;
}
int main()
{
    int grid[4][4] = {
        {2, 4, 4, 1},
        {5, 1, 1, 1},
        {5, 5, 5, 1},
        {5, 2, 1, 2},
    };
    uniquePaths(grid, 3, 3);
    return 0;
}