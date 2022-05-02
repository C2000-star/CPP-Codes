#include <iostream>
#include <algorithm>
#define N 6

void selectionSort(int arr[])
{
    for (int i = 0; i < N - 1; i++)
    {
        int minVal = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[minVal])
            {
                minVal = j;
            }
        }
        std::swap(arr[i], arr[minVal]);
    }
}
int main()
{
    int arr[N] = {7, 10, 9, 6, 8, 1};
    selectionSort(arr);

    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}