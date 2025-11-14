#include <iostream>
#include <vector>
#include <set>
using namespace std;

const long long Mod = 1e9 + 7;

int get_hash(string s){
    long long p = 29;
    long long p_pow = 1;
    long long h = 0;

    for(int i=0; i<s.size(); i++){
        h = (h + s[i] * p_pow) % Mod;
        p_pow = (p_pow * p) % Mod;
    }
}

pair<int, int> double_hash(string s){
    int h1 = get_hash(s, 29, 1e9+7);
    int h2 = get_hash(s, 31, 1e9+9);
    return {h1,h2};
}

vector<long long> get_h_p(string s){
    int n = s.size();
    vector<long long> h(n);

    h[0] = s[0];
    long long p = 29;
    long long p_pow = 29;

    for(int i=1; i<n; i++){
        h[i] = h[i-1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();

    vector<long long> pw(n);
    pw[0] = 1;
    for(int i=1; i<n; i++){
        pw[i] = pw[i-1] * 29;
    }

    vector<long long> h  = get_h_p(s);
    set<long long> dis_hashes;
    for(int i=0; i<n; i++){
        for(int j = i; j<n; j++){
            long long hash = h[j];
            if (i > 0){
                hash = hash - h[i-1];
            }
            dis_hashes.insert(hash);
        }
    }
    return 0;
}

