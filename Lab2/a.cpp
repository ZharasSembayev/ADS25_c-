#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    int x;
    cin >> x;
    int mindist = 1e9;
    int ansindex = -1;
    for (int i=0; i<n; i++){
        int d = abs(v[i] - x);
        if (d < mindist){
            mindist = d;
            ansindex = i;
        }
    }
    cout << ansindex << endl;
    return 0;
}