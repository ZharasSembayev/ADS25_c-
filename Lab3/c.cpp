#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0 ;i<n; i++){
        cin >> arr[i];
    }
    for(int t=0; t<q; t++){
        int  l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count = 0;
        for(int i=0; i<n; i++){
            int x = arr[i];
            if((x >= l1 && x <= r1) || (x >= l2 && x <= r2)){
                count ++;
            }
        }
        cout << count << endl;
    }
    return 0;
}