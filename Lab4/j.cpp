#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void buildBalancedOrder(vector<int>& arr, int left, int right, vector<int>& result) {
    if (left > right) return;
    int mid = (left + right) /2; 
    result.push_back(arr[mid]);
    buildBalancedOrder(arr, left, mid - 1, result);
    buildBalancedOrder(arr, mid + 1, right, result);
}

int main() {
    int n;
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> result;
    buildBalancedOrder(arr, 0, n - 1, result);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}