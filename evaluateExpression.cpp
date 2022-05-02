#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string A[] = {"2", "3", "+", "2", "-"};
    int first, second;
    stack<int> st;
    for (string e : A)
    {
        if (e == "+" || e == "-" || e == "*" || e == "/")
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            if (e == "+")
                st.push(first + second);
            else if (e == "-")
                st.push(first - second);
            else if (e == "*")
                st.push(first * second);
            else if (e == "/")
                st.push(first / second);
        }
        else
        {
            st.push(stoi(e));
        }
    }
    std::cout << st.top();
}