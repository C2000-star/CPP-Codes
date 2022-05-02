#include <iostream>
using namespace std;

int longestPalindrome(string s, int n)
{
    int prev = 0, temp;
    int ans[n + 1];
    for (int i = 0; i <= n; i++)
        ans[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        prev = 0;
        for (int j = 1; j <= n; j++)
        {
            temp = ans[j];
            if (s[n - j] == s[i - 1])
                ans[j] = prev + 1;
            else
                ans[j] = max(ans[j], ans[j - 1]);
            prev = temp;
        }
    }
    return ans[n];
}
int main()
{

    string s = "AATCAA";
    int n = 6;
    std::cout << "The length of longest palindromic sequence is: " << longestPalindrome(s, n);
    return 0;
}