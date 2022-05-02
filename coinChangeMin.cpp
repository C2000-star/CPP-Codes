#include <iostream>
#include <string.h>
#define N 4
#define val 4
using namespace std;

int coinChangeMin(int num, int coins[])
{
    int dp[num + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < N; j++)
        {
            if ((i - coins[j]) >= 0 && dp[i - coins[j]] >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[num] == INT_MAX)
        return -1;
    return dp[num];
}
int main()
{
    int coins[N] = {1, 3, 5};
    std::cout << "Min number of coins required for a change of " << val << " : " << coinChangeMin(val, coins);
    return 0;
}