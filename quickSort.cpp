#include <iostream>
#define N 7

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = end + 1;
    for (int j = end; j > start; j--)
    {
        if (arr[j] < pivot)
        {
            i--;
            std::swap(arr[j], arr[i]);
        }
    }
    std::swap(arr[i - 1], arr[start]);
    return i - 1;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}
int main()
{
    int arr[N] = {6, 9, 8, 5, 3, 1, 2};
    quickSort(arr, 0, N - 1);
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}