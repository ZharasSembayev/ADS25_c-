#include <iostream>
#include <vector>
using namespace std;

vector<int> get_hash(string s){
    int n = s.size();
    vector<int> h(n);
    h[0] = s[0];
    int p = 29;
    int p_pow = 29;
    for(int i=1; i<n; i++){
        h[i] = h[i-1] + s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

vector<int> get_powers(int n){
    vector<int> pw(n);
    pw[0] = 1;
    for(int i=1; i<n; i++){
        pw[i] = pw[i-1] * 29;
    }
    return pw;
}

int substring(vecot<int>& h, vector<int>& pw, int l, int r){
    int hash = h[r];
    if(l>0){
        hash = hash - h[l-1];
    }
    return hash;
}

int main(){
    string s;
    cin >> s;
    vector<int> h = get_hash(s);
    vector<int> pw = get_powers(s.size());

    for(int i=0; i<h.size(); i++){
        cout << "h[" << i << "] = " << h[i] << endl;
    }

    int l, r;
    cin >> l >> r;
    int res = substring_hash(h, pw, l, r);
    cout << res << endl;
    return 0;
}
