#include <iostream>
#include <string>
using namespace std;

string replaceDigits(std::string s) {
    for (int i = 1; i < s.length(); i += 2) {
        int temp = s[i] - '0';  // Convert char to int
        s[i] = (s[i - 1] - '0') + temp + '0';  // Convert back to char after addition
    }
    return s;
}

int main() {
    string input = "a1b2c3d4e5";
    string result = replaceDigits(input);
    cout << "Original: " << input << std::endl;
    cout << "Modified: " << result << std::endl;
    return 0;
}
