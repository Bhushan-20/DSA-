#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
       int i=0;
       for(int j=0;j<nums.size();j++){
           if(nums[j]!=0){
               swap(nums[j],nums[i]);
               i++;
           }
       }
}

int main(){
    vector<int> nums1={0,1,0,3,12};
    moveZeroes(nums1);
    for(int num:nums1){
    cout<<num<<" ";
   }
}
