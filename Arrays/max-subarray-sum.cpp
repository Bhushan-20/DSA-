#include <iostream> 
#include<algorithm>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long  sum=0; 

    long long  maxi=0;

   

    for(int i=0;i<n;i++){

        sum+=arr[i];

        maxi=max(maxi,sum);

        if(sum<0) sum=0;

    }

    return maxi;
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    long long maxSum = maxSubarraySum(arr, n);

    std::cout << "Maximum subarray sum: " << maxSum << std::endl;

    return 0;
}




