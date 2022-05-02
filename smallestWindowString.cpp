#include <iostream>
#include <vector>
using namespace std;
int lps(string s)
{
    // Your code goes here
    int n = s.size();
    vector<int> lps(n, 0);
    int j = 0;
    int i = j + 1;
    lps[0] = 0;
    while (i < n)
    {
        if (s[i] == s[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else if (j != 0)
        {

            j = lps[j - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
    if (lps[n - 1] > n / 2)
        return lps[n - 1] / 2;
    else
        return lps[n - 1];
}

int main()
{
    string s = "hellohh";
    cout << lps(s);
    return 0;
}