#include<iostream>
#include<algorithm>
using namespace std;

bool checkanagram(string str1,string str2){
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return str1==str2?true:false;
}

int main()
{
    string input1, input2;
    
    cout << "Enter the first string: ";
    cin >> input1;
    
    cout << "Enter the second string: ";
    cin >> input2;

    if (checkanagram(input1, input2)) {
        cout << "The strings are anagrams." << std::endl;
    } else {
        cout << "The strings are not anagrams." << std::endl;
    }

    return 0;
}