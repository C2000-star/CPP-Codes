#include <iostream>
#define N 7
using namespace std;

void merge(int arr[], int start, int mid, int end)
{

    int i = start;
    int j = mid + 1;
    int temp[end - start + 1];
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
    return;
}
void mergeSort(int arr[], int start, int end)
{
    while (start < end)
    {
        int m = (start + end) / 2;
        mergeSort(arr, start, m);
        mergeSort(arr, m + 1, end);
        merge(arr, start, m, end);
    }
}
void printArr(int arr[])
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[N] = {3, 6, 11, 2, 4, 7, 10};
    mergeSort(arr, 0, N - 1);
    printArr(arr);
    return 0;
}