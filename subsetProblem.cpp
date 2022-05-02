#include <iostream>
#include <bits/stdc++.h>
#define N 6
using namespace std;

int dp[100][100];
bool subsetSum(int arr[], int sum, int n)
{
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;
    if (dp[n - 1][sum] != -1)
        return dp[n - 1][sum];
    if (arr[n - 1] > sum)
        return dp[n - 1][sum] = subsetSum(arr, sum, n - 1);
    else
        return dp[n - 1][sum] = subsetSum(arr, sum, n - 1) || subsetSum(arr, sum - arr[n - 1], n - 1);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int arr[N] = {1, 4, 5, 7, 8, 10};
    int sum = 12;
    std::cout << subsetSum(arr, sum, N);
    return 0;
}