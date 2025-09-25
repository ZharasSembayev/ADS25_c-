#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int c;
    cin >> c;
    vector<int> arr(c);
    for(int i=0; i<c; i++){
        cin >> arr[i];
    }
    int n,m;
    cin >> n >> m;
    unordered_map<int, pair<int, int>> pos;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int val;
            cin >> val;
            pos[val] = {i, j};
        }
    }
    for(int i=0; i<c; i++){
        int x = arr[i];
        if (pos.find(x) != pos.end()){
            cout << pos[x].first << " " << pos[x].second << endl;
        } else{
            cout << -1 << endl;
        }
    }
    return 0;
}