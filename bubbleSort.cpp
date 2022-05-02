#include <iostream>
#define N 6

void bubbleSort(int arr[])
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}
int main()
{
    int arr[N] = {7, 10, 9, 6, 8, 1};
    bubbleSort(arr);

    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}