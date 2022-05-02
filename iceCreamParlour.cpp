#include <bits/stdc++.h>
#include <map>
using namespace std;

vector<string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money)
{
    std::map<int, int> costCount;
    int n = cost.size();
    int i, m;
    vector<int> ids;
    for (i = 0; i < n; i++)
    {
        costCount[cost[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        m = money - cost[i];
        if (ids.size() > 2)
        {
            break;
        }
        if (costCount[m] > 0)
        {
            if (m == cost[i] && costCount[m] > 1)
            {
                ids.push_back(i + 1);
            }
            else if (m != cost[i])
            {
                ids.push_back(i + 1);
            }
        }
    }
    int first = (ids[0] < ids[1]) ? ids[0] : ids[1];
    int second = (ids[0] > ids[1]) ? ids[0] : ids[1];
    std::cout << first << " " << second << std::endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++)
        {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                      { return x == y and x == ' '; });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
