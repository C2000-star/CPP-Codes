#include <bits/stdc++.h>
#include <queue>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */
int bfs(int r, int c, std::vector<string> &grid, std::vector<int, int> visited, int nextLayer)
{
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 || cc < 0)
            continue;
        if (rr >= grid[0].size() || cc >= grid.size())
            continue;
        if (grid[rr][cc] == 'X')
            continue;
        if (visited[rr][cc])
            continue;
        visited[rr][cc] = true;
        nextLayer++;
    }
    return nextLayer;
}
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    std::queue<int> row;
    std::queue<int> column;
    row.push(startX);
    column.push(startY);
    std::vector<int, int> visited;
    int currentLayer = 1;
    int nextLayer = 0;
    int moves = 0;
    int r, c;
    bool reached = false;
    while (row.size() > 0)
    {
        r = row.front();
        row.pop();
        c = column.front();
        column.pop();
        visited[r][c] = true;
        if (r == goalX && c == goalY)
        {
            reached = true;
            break;
        }
        int nextLayer = bfs(r, c, grid, visited, nextLayer);
        currentLayer--;
        if (currentLayer == 0)
        {
            currentLayer = nextLayer;
            nextLayer = 0;
            moves++;
        }
    }
    if (reached)
        return moves;
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
