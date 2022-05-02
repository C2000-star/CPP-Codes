#include <iostream>
#include <math.h>
#define N 5
#define k 3
using namespace std;
int random(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

int partition(int arr[], int l, int r, int pivot)
{
    while (true)
    {
        while (arr[l] <= pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l >= r)
            return r;
        swap(arr[l], arr[r]);
    }
}

int selection(int arr[], int l, int r, int rank)
{
    int pivot = arr[random(l, r)];
    int left = partition(arr, l, r, pivot);
    int leftSize = left - l + 1;
    if (leftSize == rank)
        return arr[left];
    else if (rank < leftSize)
        return selection(arr, l, left, rank);
    else
        return selection(arr, left + 1, r, rank - leftSize);
}
int main()
{
    int arr[N] = {3, 4, 1, 2, 5};
    std::cout << "The kth rank median is: " << selection(arr, 0, N - 1, 3);
    return 0;
}
