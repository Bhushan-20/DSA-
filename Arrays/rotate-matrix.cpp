#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
         reverse(matrix.begin(),matrix.end());

         int row=matrix.size();
         for(int i=0;i<row;i++){
             for(int j=0;j<=i;j++){
                 swap(matrix[i][j],matrix[j][i]);
            }
        }
}

int main()
{
    vector<vector<int>> matrix = {
        { 1,2,3 },
        { 4,5,6 },
        { 7,8,9 }
    };

     rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    for (const vector<int>& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

}