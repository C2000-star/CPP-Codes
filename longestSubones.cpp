#include <iostream>
#include <vector>
#define N 6
int main()
{
    int arr[N] = {4, 9, 7, 1, 8, 9};
    int maxLen = 1;
    int maxIndex;
    int maxValue = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
            maxLen++;
        if (maxValue < maxLen)
        {
            maxValue = maxLen;
            maxIndex = i - maxLen + 1;
            maxLen = 1;
        }
    }
    std::cout << maxValue << " " << maxIndex << std::endl;
}
// #include <iostream>
// using namespace std;

// void main_fun(int arr[], int n)
// {

//     int dp[4][n];
//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < n; j++)
//             dp[i][j] = 0;
//     }

//     if (arr[0] == 0)
//         dp[0][0] = 1;
//     else
//         dp[1][0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] == 0)
//             dp[0][i] = dp[0][i - 1] + 1;
//         else
//             dp[0][i] = dp[0][i - 1];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] == 1)
//             dp[1][i] = max(dp[1][i - 1] + 1,
//                            dp[0][i - 1] + 1);
//         else
//             dp[1][i] = dp[1][i - 1];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             dp[2][i] = max(dp[2][i - 1] + 1,
//                            max(dp[1][i - 1] + 1,
//                                dp[0][i - 1] + 1));
//         }
//         else
//             dp[2][i] = dp[2][i - 1];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] == 1)
//         {
//             dp[3][i] = max(dp[3][i - 1] + 1,
//                            max(dp[2][i - 1] + 1,
//                                max(dp[1][i - 1] + 1,
//                                    dp[0][i - 1] + 1)));
//         }
//         else
//             dp[3][i] = dp[3][i - 1];
//     }
//     int ans = max(dp[2][n - 1], max(dp[1][n - 1], max(dp[0][n - 1], dp[3][n - 1])));
//     cout << (ans);
// }

// int main()
// {
//     int n = 8;
//     int arr[] = {0, 1, 0, 0, 1, 1, 1, 0};

//     main_fun(arr, n);
//     return 0;
// }
