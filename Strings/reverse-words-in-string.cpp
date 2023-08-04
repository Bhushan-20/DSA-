#include<iostream>
#include<algorithm>
using namespace std;

string reverseWords(string s) {
        s.push_back(' ');
        string ans, st;
        for(auto c: s) {
            if(c == ' ') {
                reverse(st.begin(), st.end());
                ans += st;
                ans += ' ';
                st.clear();
            }
            else st.push_back(c);
        }
        ans.pop_back();
        return ans;
    }



int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    string reversedWordsString = reverseWords(inputString);

    cout << "Original String: " << inputString << endl;
    cout << "String with Reversed Words: " << reversedWordsString << endl;

    return 0;
}