#include <iostream>
#define M 5
#define N 5
using namespace std;
int uniquePaths(int x, int y)
{
    int dp[M][N];
    dp[0][0] = 1;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
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
    std::cout << "Number of unique paths with obstacles: " << uniquePaths(4, 4);
    return 0;
}