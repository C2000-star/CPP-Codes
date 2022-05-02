#include <iostream>
#include <string.h>
#define N 4
#define val 4
using namespace std;

int coinChange(int num, int coins[])
{
    int dp[num + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i - coins[j]) >= 0)
            {
                dp[i] += dp[i - coins[j]];
            }
        }
    }
    return dp[num];
}
int main()
{
    int coins[N] = {1, 3, 5, 10};
    std::cout << coinChange(val, coins);
    return 0;
}