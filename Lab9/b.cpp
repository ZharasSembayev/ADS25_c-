#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int KMP(string text, string pattern){
    string s = pattern + '#' + text;
    int n = s.size();
    int m = pattern.size();
    vector<int> pi = prefix_function(s);
    int count = 0;
    for(int i=0; i<n; i++){
        if(pi[i] == m){
            count++;
        }
    }
    return count;
}

int main(){
    string text, pattern;
    int k;
    cin >> pattern >> k >> text;
    if(KMP(text, pattern) >= k){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}