// Find the number of numbers less than or equal to N that do not have consecutive ones
// in its binary representation
// time constraint: 1<=N<=10^9

#include <iostream>
#define N 3
using namespace std;

int fibbinary(int x)
{
    if (x & (x >> 1) == 0)
        return 0;
    return 1;
}
int main()
{
    int dp[N + 1];
    for (int i = 0; i <= N; i++)
        dp[i] = 0;

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = dp[i - 1] + fibbinary(i);
    }

    std::cout << dp[N];
    return 0;
}
