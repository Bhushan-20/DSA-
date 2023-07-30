//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k){
    int n=nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }
        nums=temp;
}

int main(){
    vector<int>nums1={2,5,9,8,7};
    int n=2;
    rotate(nums1,n);
    for(int num:nums1){
    cout<<num<<" ";
   }
}