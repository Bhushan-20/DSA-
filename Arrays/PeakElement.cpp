#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findPeakElement(vector<int> &arr) {

    // Write your code here

    int n =arr.size();

    if(n == 1) return 0;

    if(arr[0] > arr[1]) return 0;

    if(arr[n-1] > arr[n-2]) return n-1;
    
    int start = 1, end = n-2;
    
    while(start<=end){

        int mid = start +(end - start) / 2;
        
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(arr[mid] > arr[mid-1]){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1 ,8, 1, 5 ,3}; // Example input array

    int peakIndex = findPeakElement(arr);

    if (peakIndex != -1) {
        cout << "Peak element is at index: " << peakIndex << ", value: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak element found in the array." << endl;
    }

    return 0;
}