//odd positions are smaller than either side
#include <iostream>
#define n 5
using namespace std;
int main()
{
    int A[n] = {3, 4, 7, 2, 6};
    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
        arr1[i] = 0;
    for (int i = 0; i < n; i++)
        arr2[i] = 0;
    arr1[0] = 0;
    if (A[0] < A[1])
        arr2[0] = 0;
    else
        arr2[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (i < n - 1 && i % 2 == 1 && A[i] >= A[i + 1])
            arr1[i] = arr1[i - 1] + 1;
        else
            arr1[i] = arr1[i - 1];
    }

    //even psoitions are smaller than either side

    for (int i = 1; i < n; i++)
    {
        if (i < n - 1 && i % 2 == 0 && A[i] >= A[i + 1])
            arr2[i] = arr2[i - 1] + 1;
        else
            arr2[i] = arr2[i - 1];
    }

    cout << min(arr1[n - 1], arr2[n - 1]);
    return 0;
}