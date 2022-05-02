#include <iostream>
#include <string.h>
#define N 3
#define val 3
using namespace std;

int coinChangeUnique(int num, int coins[])
{
    int dp[num + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int j = 0; j < N; j++)
    {
        for (int i = 1; i <= num; i++)
        {
            if ((i - coins[j]) >= 0)
            {
                dp[i] += dp[i - coins[j]];
            }
        }
    }
    return dp[num];
    // int dp[num + 1][N];
    // memset(dp, 0, sizeof dp);
    // for (int i = 0; i < N; i++)
    // {
    //     dp[0][i] = 1;
    // }
    // for (int i = 1; i <= num; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         for (int k = 0; k <= j; k++)
    //         {
    //             if ((i - coins[k]) >= 0)
    //                 dp[i][j] += dp[i - coins[k]][k];
    //         }
    //     }
    // }
    // return dp[num][N - 1];
}
int main()
{
    int coins[N] = {1, 2, 3};
    std::cout << "Number of unique ways: " << coinChangeUnique(val, coins);
    return 0;
}