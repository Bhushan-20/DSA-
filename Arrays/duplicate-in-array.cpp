#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    int ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;){
        if(arr[i]==arr[i+1]){
            ans=arr[i];
            i=i+2;
        }
        else{
            i++;
        }
    }
    return ans;

	
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5, 6, 7,};
    
    int duplicate = findDuplicate(arr);

    cout << "Duplicate element in the array: " << duplicate << endl;

    return 0;
}
