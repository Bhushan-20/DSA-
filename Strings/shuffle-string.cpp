#include<iostream>
#include<vector>
using namespace std;

string restoreString(string s, vector<int>& indicies) {
        int n = s.size() ; 
        string temp = s ; 
       for( int i = 0 ; i <n ; i++) 
       {
           s[indicies[i]]= temp[i] ; 
       }

       return s ; 
}

int main(){
    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    
    string restoredString = restoreString(s, indices);
    cout << "Restored String: " << restoredString << endl;
    
    return 0;
}