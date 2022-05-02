#include <iostream>
#define M 5
#define N 5
using namespace std;
int uniquePaths(int grid[][4], int x, int y)
{
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
    return dp[x][y];
}
int main()
{
    int grid[4][4] = {
        {2, 4, 4, 1},
        {5, 1, 1, 1},
        {5, 5, 5, 1},
        {5, 2, 1, 2},
    };
    std::cout << "The path with maximum cost: " << uniquePaths(grid, 3, 3);
    return 0;
}