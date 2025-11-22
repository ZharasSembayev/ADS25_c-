#include <iostream>
#include <string>
#include <vector>
using namespace std;

int get_hash(string s){
    int p = 29;
    int p_pow = 1;
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

vector<int> hash_prefix(string s){
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

vector<int> get_power(int n){
    vector<int> p(n);
    p[0] = 1;
    for(int i=1; i<n; i++){
        p[i] = p[i-1] * 29;
    }
}

int substring_hash(int l, int r){
    int hash = h[r];
    if (l > 0){
        hash = hash - h[l-1];
    }
    return hash;
}
