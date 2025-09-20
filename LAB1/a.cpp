#include <iostream>
#include <deque>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        deque<int> d;
        for (int i=n; i>= 1; --i){
            d.push_front(i);
            int m = d.size();
            int k = i % m;
            for(int j = 0; j < k; ++j){
                int x = d.back();
                d.pop_back();
                d.push_front(x);
            }
        }
        for (int i=0; i<d.size(); i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
    return 0;
}