#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    int mx = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    if(r < n){
        cout << -1 << endl;
        return 0;
    }
    int L = 1, H = mx;
    while(L < H){
        int mid = L + (H - L) / 2;
        int fl = 0;
        for(int x : arr){
            fl += (x + mid - 1) / mid;
            if (fl > r){
            break;
            }
        }
        if (fl <= r){
            H = mid;
        } else {
            L = mid +1;
        }
    }
    cout << L << endl;
    return 0;
}