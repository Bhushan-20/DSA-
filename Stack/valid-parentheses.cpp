#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            if (!st.empty()) {
                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (isValidParenthesis(input)) {
        cout << "The given string has valid parentheses." << endl;
    } else {
        cout << "The given string has invalid parentheses." << endl;
    }

    return 0;
}
