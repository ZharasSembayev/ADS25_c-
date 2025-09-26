#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> pref(n+1, 0);
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i] + arr[i];
    }
    int q;
    cin >> q;
    while(q--){
        int p;
        cin >> p;
        int index = (int)(upper_bound(arr.begin(), arr.end(), p) - arr.begin());
        int count = index;
        int sum = pref[index];
        cout << count << " " << sum << endl;
    }
    return 0;
}