#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberPainters(int arr[], int n, int mid)
    {
        int time = 0;
        int painters = 1;
        for (int i = 0; i < n; i++)
        {
            time += arr[i];
            if (time > mid)
            {
                ++painters;
                time = arr[i];
            }
        }
        return painters;
    }
    long long minTime(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int low = arr[n - 1];
        int high = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            high += arr[i];

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int painters = numberPainters(arr, n, mid);
            if (painters <= k)
            {
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int n = 11;
    int k = 6;
    int arr[n] = {21, 17, 3, 12, 21, 8, 11, 4, 8, 22, 24};
    Solution obj;
    cout << obj.minTime(arr, n, k) << endl;
    return 0;
}