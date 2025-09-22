#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    map<int, int> m;
    for (int x : v){
        m[x]++;
    }
    int max = 0;
    for(auto p : m){
        if (p.second > max){
            max = p.second;
        }
    }
    vector<int> v1;
    for(auto p : m){
        if (p.second == max){
            v1.push_back(p.first);
        }
    }
    sort(v1.rbegin(), v1.rend());
    for(int i=0; i<v1.size(); i++){
        cout<< v1[i] << " ";
    }
    cout << endl;

    return 0;
}