#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            if(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return nums.size() + 1;
}
int main() {
    vector<int> nums = {3, 4, -1, 1};
    int result = firstMissingPositive(nums);
    cout << "The first missing positive integer is: " << result << endl;
    return 0;
}