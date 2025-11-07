#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

using ull = unsigned long long;
const ull p = 29;

int main(){
    int n;
    cin >> n;
    vector<ull> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    for(int i=0; i<h.size(); i++){
        if(i==0){
            char c = char(97+h[i]);
            cout << c;
        } else{
            ull hash = h[i] - h[i-1];
            ull num = (97 * pow(2, i) + hash) / pow(2,i);
            char c = char(num);
            cout << c;
        }
    }
    return 0;
}

