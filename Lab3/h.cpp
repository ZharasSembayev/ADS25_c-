#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> pref(n);
    pref[0] = arr[0];
    for(int i=1; i<n; i++){
        pref[i] = pref[i-1] + arr[i];
    }
    for(int i=0; i<k; i++){
        int line ;
        cin >> line;
        int b = lower_bound(pref.begin(), pref.end(), line) - pref.begin() + 1;
        cout << b << endl;
    }

    return 0;
}