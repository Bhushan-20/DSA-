#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
        int s= nums.size() - 1;
        sort(nums.begin(),nums.end());
         int i = s;
         int j = s-1;
    return (nums[i])*(nums[j]);
}

int main(){
    vector<int> nums = {3, 4, 5, 2};
    
    int result = maxProduct(nums);
    
    cout << "Maximum product of two largest elements: " << result << endl;
    
    return 0;
}