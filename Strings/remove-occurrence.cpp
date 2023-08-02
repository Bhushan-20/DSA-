#include <iostream>
using namespace std;

string removeOccurrences(string s, string part) {
    while (s.length() != 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string inputString, partToRemove;
    
    cout << "Enter the main string: ";
    getline(cin, inputString);

    cout << "Enter the part to remove: ";
    getline(cin, partToRemove);

    string result = removeOccurrences(inputString, partToRemove);

    cout << "String after removing occurrences of \"" << partToRemove << "\":\n";
    cout << result << endl;

    return 0;
}
