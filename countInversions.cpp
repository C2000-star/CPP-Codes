#include <iostream>
#define N 6
using namespace std;

int merge(int arr[], int temp[], int l, int m, int r)
{
    int i, j, k;
    int countI = 0;
    i = l;
    j = m;
    k = l;
    while ((i <= m - 1) && (j <= r))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            countI = countI + (m - i);
        }
    }
    while (i <= m - 1)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return countI;
}
int mergeSort(int arr[], int temp[], int l, int r)
{
    int mid, countI = 0;
    if (l < r)
    {

        mid = (r + l) / 2;
        countI += mergeSort(arr, temp, l, mid);
        countI += mergeSort(arr, temp, mid + 1, r);

        countI += merge(arr, temp, l, mid + 1, r);
    }
    return countI;
}
int main()
{
    int arr[N] = {1, 2, 4, 3, 2, 5};
    int temp[N - 1];
    std::cout << "Number of inversions: " << mergeSort(arr, temp, 0, N - 1);
    return 0;
}