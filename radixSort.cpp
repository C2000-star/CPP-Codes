#include <iostream>
#include <algorithm>
#define N 7
using namespace std;
void countSort(int arr[], int place)
{
    int count[10];
    int sortedArray[N];
    for (int i = 0; i < 10; i++)
        count[i] = 0;

    for (int i = 0; i < N; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        int index = (arr[i] / place) % 10;
        sortedArray[count[index] - 1] = arr[i];
        count[index]--;
    }
    for (int i = 0; i < N; i++)
    {
        arr[i] = sortedArray[i];
    }
}
void radixSort(int arr[])
{
    int maxElement = *max_element(arr, arr + N);
    for (int place = 1; maxElement / place > 0; place *= 10)
    {
        countSort(arr, place);
    }
}
int main()
{
    int arr[7] = {57, 41, 91, 3000, 100, 62, 62};
    radixSort(arr);

    for (int i = 0; i < N; i++)
        std::cout << arr[i] << " ";
    return 0;
}