#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    int maxval = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x; 
        arr.push_back(x);
        maxval = max(maxval, arr[i]);
    }
    int L = 1; int R = maxval;
    while(L < R){
        int mid = (L + R) / 2;
        long long hours = 0;
        for (int i : arr){
            hours += (i + mid - 1) / mid;
        }
        if (hours <= k){
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << L << endl;

    return 0;
}