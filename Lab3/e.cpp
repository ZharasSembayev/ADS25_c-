#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), x1(n), y1(n);
    int mxcoord = 0;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> x1[i] >> y1[i];
        mxcoord = max(mxcoord, max(x1[i], y1[i]));
    }
    int l = 0, h = mxcoord;
    while(l < h){
        int mid = l + (h - l) / 2;
        int count = 0;
        for(int i=0; i<n; i++){
            if(x1[i] <= mid && y1[i] <= mid){
                count ++;
            }
        }
        if (count >= k){
            h = mid;
        } else {
            l = mid +1;
        }
    }
    cout << l << endl;
    return 0;
}