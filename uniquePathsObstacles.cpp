#include <iostream>
#define M 5
#define N 5
using namespace std;
int uniquePaths(int grid[][4], int x, int y)
{
    int dp[M][N];
    dp[0][0] = 1;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (grid[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0 && j > 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            else if (i > 0)
                dp[i][j] = dp[i - 1][j];
            else if (j > 0)
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[x][y];
}
int main()
{
    int grid[4][4] = {
        {0, 0, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
    };
    std::cout << "Number of unique paths with obstacles: " << uniquePaths(grid, 3, 3);
    return 0;
}