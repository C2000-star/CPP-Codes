#include <iostream>
using namespace std;
void permute(string s, int l, int r)
{
    if (l == r)
        std::cout << s << std::endl;
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]);
    }
}
int main()
{
    string s = "ABCD";
    int n = s.size();
    permute(s, 0, n - 1);
    return 0;
}