#include <iostream>
#define N 10
using namespace std;

void countingSort(int A[], int n, int sortedArray[])
{
    int count[N] = {0};
    int index;
    for (int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    for (int i = 1; i < N; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        index = A[i];
        sortedArray[count[index] - 1] = index;
        count[index]--;
    }
}
int main()
{
    int n = 9;
    int A[] = {2, 1, 7, 5, 7, 3, 2, 6, 8};
    int sortedArray[n];
    countingSort(A, n, sortedArray);
    for (int i = 0; i < n; i++)
    {
        std::cout << sortedArray[i] << " ";
    }
    return 0;
}