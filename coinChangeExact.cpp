#include <iostream>
#include <string.h>
#define N 4
#define s 3
#define c 3
using namespace std;

int coinChangeExact(int n, int t, int coins[])
{
    int dp[n + 1][t + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (i > 0 && j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 0; k < N; k++)
            {
                if (i >= coins[k])
                {
                    dp[i][j] += dp[i - coins[k]][j - 1];
                }
            }
        }
    }
    return dp[n][t];
}
int main()
{
    int coins[N] = {1, 2, 3, 5};
    std::cout << "Number of ways in which exactly " << c << " coins add upto " << s << " is: " << coinChangeExact(s, c, coins);
    return 0;
}