#include <iostream>
#include <algorithm>
#include <vector>
#define N 7
using namespace std;

bool isNobel(int i, int arr[N], int val)
{
    vector<int> ans(i * 3);
    for (int k = 0; k < i; k++)
    {
        for (int j = 1; j <= 3; j++)
            ans.push_back(arr[k]);
    }
    for (int k = 0; k < (i - k) * 3; k++)
    {
        int l = k + 1, r = i * 3 - 1;

        while (l < r)
        {
            if (ans[k] + ans[l] + ans[r] == val)
                return true;
            else if (ans[k] + ans[l] + ans[r] < val)
                l++;
            else
                r--;
        }
    }
    return false;
}
int main()
{
    int arr[N] = {2, 3, 4, 9, 16, 7, 9};
    int countNobel = 0;
    for (int i = 1; i < N; i++)
    {
        if (isNobel(i, arr, arr[i]))
            countNobel++;
    }
    cout << countNobel;
    return 0;
}