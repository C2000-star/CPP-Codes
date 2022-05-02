#include <iostream>
#include <vector>
#define N 8

int checkFibbinary(int x)
{
    if ((x & (x >> 1)) == 0)
        return 1;
    return 0;
}
int findNumbers(int n)
{
    std::vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i] + dp[i - 1] + checkFibbinary(i);
    }
    return dp[n];
}
int main()
{
    std::cout << findNumbers(N) << std::endl;
    return 0;
}