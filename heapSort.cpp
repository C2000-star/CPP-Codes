#include <iostream>
#define N 7

void heapify(int arr[], int i, int n)
{
    int l = 2 * i + 1;
    int r = l + 1;
    int minIndex = i;
    if (l < n && arr[l] < arr[i])
    {
        minIndex = l;
    }
    if (r < n && arr[r] < arr[minIndex])
    {
        minIndex = r;
    }

    if (minIndex != i)
    {
        std::swap(arr[i], arr[minIndex]);
        heapify(arr, minIndex, n);
    }
}
void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}
void heapSort(int arr[], int s, int n)
{
    buildMinHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
int main()
{
    int arr[N] = {1, 3, 8, 5, 6, 7, 1};
    heapSort(arr, 0, N);
    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}