#include<bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)

{
    vector<int> ans;

    for(int col=0;col<mCols;col++){
        if(col & 1){
            for(int row=nRows-1;row>=0;row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            for(int row=0;row<nRows;row++){
                    ans.push_back(arr[row][col]);

            }
        }
    }
    return ans;

}

int main() {
    int nRows, mCols;
    
    cout << "Enter the number of rows: ";
    cin >> nRows;

    cout << "Enter the number of columns: ";
    cin >> mCols;

    vector<vector<int>> matrix(nRows, vector<int>(mCols));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < mCols; j++) {
            cin >> matrix[i][j];
        }
    }

    
    vector<int> result = wavePrint(matrix, nRows, mCols);

    cout << "Wave Printed elements: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}