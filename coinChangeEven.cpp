#include <iostream>
#include <string.h>
#define N 4
#define s 4
using namespace std;

int coinChangeExact(int n, int coins[])
{
    int dp[n + 1][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 0; i <= n; i++)
    {

        for (int k = 0; k < N; k++)
        {
            if (i >= coins[k])
            {
                dp[i][0] += dp[i - coins[k]][1];
                dp[i][1] += dp[i - coins[k]][0];
            }
        }
    }
    return dp[n][1];
}
int main()
{
    int coins[N] = {1, 2, 3, 5};
    std::cout << "Number of ways in which even number of coins add upto " << s << " is: " << coinChangeExact(s, coins);
    return 0;
}