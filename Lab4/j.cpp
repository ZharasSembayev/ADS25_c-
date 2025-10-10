#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result;

void buildBalanced(vector<int>& arr, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;
    result.push_back(arr[mid]); 
    buildBalanced(arr, l, mid - 1);
    buildBalanced(arr, mid + 1, r); 
}

int main() {
    int h;
    cin >> h;
    int n = (1 << h) - 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sort(arr.begin(), arr.end());
        buildBalanced(arr, 0, n - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i != n - 1) cout << " ";
    }
    cout << "\n";
    return 0;
}