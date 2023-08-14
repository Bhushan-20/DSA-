#include<iostream>
#include<vector>
using namespace std;
vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++){
            int index = nums[i];
            ans.push_back(nums[index]);
        }

        return ans;

}
int main()
{
    vector<int> input = {3, 0, 2, 1};
    
    vector<int> result = buildArray(input);
    
    cout << "Input array: ";
    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Result array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}