#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0, c=n-1;

        while(r<m and c>=0){
            if(matrix[r][c]==target) return true;
            matrix[r][c]>target ? c-- : r++;
        }
        return false;
}



int main() {
    int nRows;
    cin>>nRows;
    int mCols;
    cin>>mCols;
    vector<vector<int>> matrix(nRows, vector<int>(mCols));
    cout<<"Enter Elements = ";
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < mCols; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin>>target;

    bool found = searchMatrix(matrix, target);

    cout << "Target  found: " << (found ? "true" : "false") << endl;

    return 0;
}