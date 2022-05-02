#include <iostream>
#define N 8

void printKadane(int l, int r, int arr[])
{
    for (int i = l; i <= r; i++)
        std::cout << "  " << i;
    std::cout << std::endl;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] < 0)
            std::cout << " " << arr[i];
        else
            std::cout << "  " << arr[i];
    }
}
void kadane(int arr[])
{
    int max1 = 0, max2 = INT_MIN;
    int l, r;
    for (int i = 0; i < N; i++)
    {
        max1 += arr[i];
        if (max1 < arr[i])
        {
            max1 = arr[i];
            l = i;
        }
        if (max2 < max1)
        {
            max2 = max1;
            r = i;
        }
    }
    std::cout << "The maximum sum is: " << max2 << std::endl;
    std::cout << "The contiguous subarray with maximum sum is: " << std::endl;
    printKadane(l, r, arr);
}
int main()
{
    int arr[N] = {-2, -3, 4, -1, -2, 1, 5, -3};
    kadane(arr);
    return 0;
}