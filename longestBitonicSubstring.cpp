#include <iostream>
#include <vector>
#define N 7

int main()
{
    int arr[N] = {1, 2, 11, 5, 2, 3, 1};
    std::vector<int> inc(N, 1);
    std::vector<int> dec(N, 1);
    for (int i = 1; i < N; i++)
        if (arr[i] > arr[i - 1])
            inc[i] = inc[i - 1] + 1;

    for (int i = N - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            dec[i] = dec[i + 1] + 1;

    int maxLen = 0;

    for (int i = 0; i < N; i++)
        maxLen = std::max(maxLen, inc[i] + dec[i] - 1);

    std::cout << "Longest Bitonic Substring is: " << maxLen;
}