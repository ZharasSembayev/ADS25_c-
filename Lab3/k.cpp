#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = n+1;
    int sum = 0;
    int l = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        while (sum >= k){
            ans = min(ans, i - l + 1);
            sum -= arr[l];
            l++;
        }

    }
    cout << ans << endl;
    return 0;
}