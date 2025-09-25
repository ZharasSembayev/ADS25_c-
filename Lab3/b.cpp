#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long sum = 0;
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > mx) mx = a[i];
    }
    long long L = mx, R = sum;
    while (L < R) {
        long long mid = L + (R - L) / 2;
        int cnt = 1;
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur + a[i] <= mid) cur += a[i];
            else { ++cnt; cur = a[i]; }
        }
        if (cnt <= k) R = mid;
        else L = mid + 1;
    }
    cout << L << "\n";
    return 0;
}