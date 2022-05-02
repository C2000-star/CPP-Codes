//odd positions are smaller than either side
#include <iostream>
#include <vector>
#define n 5
using namespace std;

vector<int> perm(int x, int y)
{
    vector<int> ans;
    if(x!=y){
    ans.push_back(10 * x + x);
    ans.push_back(10 * x + y);
    ans.push_back(10 * y + x);
    ans.push_back(10 * y + y);
    }
    else
        ans.push_back(10*x + y);
    return ans;
}
int main()
{
    int HH1[2] = {2, 3};
    int MM1[2] = {2, 2};
    int SS1[2] = {0, 0};
    int HH2[2] = {2, 5};
    int MM2[2] = {2, 4};
    int SS2[2] = {2, 3};
    vector<int> ans;
    ans = perm(HH1[0], HH1[1]);
    int count = 0;
    int x = HH1[0], y = HH1[1];
    int a = HH2[0], b = HH2[1];
    for (int i = 0; i < ans.size(); i++)
    {
        if ((10*x + y) <= ans[i] && ans[i] <= (10 * b + a))
        {
            count++;
        }
    }

    
    
}