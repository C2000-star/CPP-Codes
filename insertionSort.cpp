#include <iostream>
#define N 6

void insertionSort(int arr[])
{
    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[N] = {7, 10, 9, 6, 8, 1};
    insertionSort(arr);

    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}