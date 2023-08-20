#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int sumPages = 0;
    int allocation = 1;
    for (int i = 0; i < n; i++) {
        if (sumPages + arr[i] <= mid) {
            sumPages += arr[i];
        } else {
            allocation++;
            if (allocation > m || arr[i] > mid)
                return false;
            sumPages = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n)
        return -1;
    int start = 0;
    int end = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
        end += arr[i];

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else
            start = mid + 1;
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of books: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the number of students: ";
    cin >> m;
    cout << "Enter the number of pages in each book:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = findPages(arr, n, m);
    cout << "Minimum pages allocated: " << result << endl;
    return 0;
}
