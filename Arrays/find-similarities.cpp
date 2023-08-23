#include <bits/stdc++.h>

using namespace std;

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m) {
    int cnt = 0;
    pair<int, int> res;

    if (n >= m) {
        for (int i = 0; i < n; i++) {
            if (find(arr1.begin(), arr1.end(), arr2[i]) != arr1.end()) {
                cnt++;
            }
        }
        res = make_pair(cnt, (m + n) - cnt);
    } else if (m > n) {
        for (int i = 0; i < n; i++) {
            if (find(arr2.begin(), arr2.end(), arr1[i]) != arr2.end()) {
                cnt++;
            }
        }
        res = make_pair(cnt, (m + n) - cnt);
    }

    return res;
}

int main() {
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    pair<int, int> result = findSimilarity(arr1, arr2, n, m);
    cout << "Number of common elements: " << result.first << endl;
    cout << "Number of non-common elements: " << result.second << endl;

    return 0;
}
