#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(),ans.end());
        
        return ans;
}

int main(){
     vector<int> input = {-4, -2, 0, 1, 3, 5};
    vector<int> result = sortedSquares(input);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}