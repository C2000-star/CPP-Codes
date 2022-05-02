#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, string> lookup;

bool isValid(int i, int j, int N)
{
    return (i >= 0 && i < N && j >= 0 && j < N);
}

string findLongestPath(vector<vector<int>> const &mat, int i, int j)
{

    int N = mat.size();

    if (!isValid(i, j, N))
    {
        return 0;
    }

    string key = to_string(i) + "|" + to_string(j);

    if (lookup.find(key) == lookup.end())
    {

        string path;
        if (i > 0 && mat[i - 1][j] - mat[i][j] == 1)
        {
            path = findLongestPath(mat, i - 1, j);
        }
        if (j + 1 < N && mat[i][j + 1] - mat[i][j] == 1)
        {
            path = findLongestPath(mat, i, j + 1);
        }

        if (i + 1 < N && mat[i + 1][j] - mat[i][j] == 1)
        {
            path = findLongestPath(mat, i + 1, j);
        }

        if (j > 0 && mat[i][j - 1] - mat[i][j] == 1)
        {
            path = findLongestPath(mat, i, j - 1);
        }

        if (path.size() > 0)
        {
            lookup[key] = to_string(mat[i][j]) + ", " + path;
        }
        else
        {
            lookup[key] = to_string(mat[i][j]);
        }
    }

    return lookup[key];
}

string longestPath(vector<vector<int>> const &mat)
{
    string result;
    string str;
    int res_size = INT_MIN;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {

            string path = findLongestPath(mat, i, j);

            int size = count(path.begin(), path.end(), ',');

            if (size > res_size)
            {
                result = path, res_size = size;
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> mat =
        {
            {10, 13, 14, 21, 23},
            {11, 9, 22, 2, 3},
            {12, 8, 1, 5, 4},
            {15, 24, 7, 6, 20},
            {16, 17, 18, 19, 25}};

    cout << longestPath(mat) << endl;

    return 0;
}