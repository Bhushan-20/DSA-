#include <iostream>
using namespace std;

bool isPalindrome(string &s){
    int n = s.length();
    int start = 0;
    int e = n - 1;
    while (start <= e)
    {
        if (s[start] != s[e])
        {
            return false;
        }
        else
        {
            start++;
            e--;
        }
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    bool result = isPalindrome(str);

    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
