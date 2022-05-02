#include <iostream>

using namespace std;
int LCS(string s1, string s2)
{
    if (s1.size() > s2.size())
        LCS(s2, s1);

    int n1 = s1.size();
    int n2 = s2.size();
    int prev, temp, arr[n2 + 1];
    for (int i = 0; i <= n2; i++)
        arr[i] = 0;
    for (int i = 1; i <= n1; i++)
    {
        prev = 0;
        for (int j = 1; j <= n2; j++)
        {
            temp = arr[j];
            if (s1[i - 1] == s2[j - 1])
                arr[j] = prev + 1;
            else
                arr[j] = max(arr[j], arr[j - 1]);
            prev = temp;
        }
    }
    return arr[n2];
}
int main()
{
    string s1 = "GHUQAB";
    string s2 = "AHUTA";
    std::cout << "Longest Common Subsequence: " << LCS(s1, s2);
    return 0;
}