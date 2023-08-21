#include<iostream>
#include<vector>
using namespace std;

string sortSentence(string s) {

       vector<string>words(10);
       string temp = "";
       for(int i = 0 ; i < s.size() ; i++)
       {
           if(s[i]>='0' && s[i]<='9')
           {
               words[s[i]-'1'] = temp + " ";
               temp = "";
               i++;
           }else{
                temp += s[i];
           }
       }
       temp = "";
       for(int i = 0 ; i < words.size() ; i++)
       {
           temp += words[i];
       }
       temp.pop_back();
       return temp;

        
}

int main() {
    string input = "is2 sorted4 this1 a3 sentence5";
    string sortedSentence = sortSentence(input);
    cout << "Original sentence: " << input << endl;
    cout << "Sorted sentence: " << sortedSentence << endl;
    return 0;
}