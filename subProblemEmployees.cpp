// There are k sub problems and an array A.
// ith element in A is the number of days required by ith employee to finish one subproblem
// find the minimum time required to finish k subproblems
// All N employees can be used to finish the subproblems

#include <iostream>
#include <vector>
#define N 3
#define k 6

int check(int arr[], int mid)
{
    int ans = 0;
    std::vector<int> deadline;
    for (int i = 0; i < N; i++)
    {
        deadline.push_back(arr[i]);
    }
    for (int i = 1; i <= mid; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (deadline[j] == i)
            {
                ans++;
                deadline[j] += arr[j];
            }
        }
    }
    return ans;
}
int main()
{
    int arr[N] = {1, 2, 2};
    int l = 1;
    int h = arr[0] * k;
    int ans = h;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(arr, mid) >= k)
        {
            h = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << "The minimum time is: " << ans << std::endl;
    return 0;
}
