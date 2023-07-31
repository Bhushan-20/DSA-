#include<iostream>
#include<vector>
using namespace std;


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0, j = 0;
    vector<int> ans;
    while(i < n && j < m){

        if(arr1[i] == arr2[j]){

            ans.push_back(arr1[i]);

            i++;

            j++;

        }

        else if(arr1[i] < arr2[j]){

            i++;

        }

        else{

            j++;

        }

    }

    return ans;
}

int main(){

    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {3, 5, 6, 8, 9, 10};
    
    vector<int> intersection = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());

    cout << "Intersection of the arrays: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}