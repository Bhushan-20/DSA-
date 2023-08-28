/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<unordered_set>

using namespace std;
void Union(int *arr1,int *arr2,int m,int n){
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
 
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
 
        else {
            cout << arr2[j++] << " ";
            i++;
        }
    }
 
    /* Print remaining elements of the larger array */
    while (i < m)
        cout << arr1[i++] << " ";
 
    while (j < n)
        cout << arr2[j++] << " ";
}
void intersection(int *arr1,int *arr2,int m,int n){
    /*
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr2[j]<<endl;
                arr2[j]=-1;
                break;
            }
        }
    }
}*/
 unordered_set<int> seen;

    for (int i = 0; i < m; i++) {
        seen.insert(arr1[i]);
    }

    for (int j = 0; j < n; j++) {
        if (seen.find(arr2[j]) != seen.end()) {
            cout << arr2[j] << endl;
            seen.erase(arr2[j]);
        }
    }
}

int main()
{
    int arr1[5]={1,2,3,5,7};
    int arr2[4]={2,4,6,8};
    cout<<"Union of two arrays = ";
    Union(arr1,arr2,5,4);
    cout<<endl;
    cout<<"Intersection between two arrays = ";
    intersection(arr1,arr2,5,4);
    
    return 0;
}
