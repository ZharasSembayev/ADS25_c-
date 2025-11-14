#include <iostream>
#include <vector>
using namespace std;

vector<int> pref_func_naive(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++){
        for(int len = i; len > 0; len--){
            bool match = true;
            for(int j=0; j<len; j++){
                if(s[j] != s[i - len + 1 + j]){
                    match = false;
                    break;
                }
            }
            if(match){
                pi[i] = len;
                break;
            }
        }
    }
    return pi;
}

int main(){
    string s;
    cin >> s;
    vector<int> pi = pref_func_naive(s);
    for(int i=0; i<pi.size(); i++){
        cout << pi[i] << " ";
    }
    return 0;
}