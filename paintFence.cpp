#include <iostream>
#define N 4
using namespace std;

int paintFence(int m)
{
    int dp[m][2];

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 2;
    dp[1][1] = 2;

    for (int i = 2; i < m; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            dp[i][j] = dp[i - 1][1 - j] + dp[i - 2][1 - j];
        }
    }
    return dp[m - 1][0] + dp[m - 1][1];
}

int main()
{
    std::cout << "Number of ways of painting fence: " << paintFence(N);
    return 0;
}