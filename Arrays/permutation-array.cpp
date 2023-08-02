#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
         do {
        result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        return result;
        
}

int main() {
    vector<int> nums = {1, 2, 3}; // Example input vector

    vector<vector<int>> permutations = permute(nums);

    cout << "All permutations of the input vector are:" << endl;
    for ( auto perm : permutations) {
        for (auto num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}