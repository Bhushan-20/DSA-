#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(std::vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            nums[i - count] = nums[i];
        }
    }
    return nums.size() - count;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6};
    
    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int newSize = removeDuplicates(nums);

    cout << "Vector after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << std::endl;

    cout << "New size of the vector: " << newSize << endl;

    return 0;
}
