#include <iostream>
#include <vector>
using namespace std;


vector<int> prefix_function_naive(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i=1; i<n; i++){
        for(int len = i; len > 0; len--){
            bool match = true ;
            for(int j = 0; j<len; j++){
                if(s[j] != s[i - len + 1 + j]){
                    match = true;
                    break;
                }
            }
            if (match){
                pi[i] = len;
                break;
            }

        }
    }
    retunr pi;
}

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i=1; i<n; i++){
        int j = pi[i-1];

        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }

        if(s[i] == s[j]){
            j++;
        }

        pi[i] = j;
    }
    return p;
}

void KMP(string text , string pattern){
    string s = pattern + '#' + text;
    int n = s.size();
    int m = pattern.size();
    vector<int> pi = prefix_function(s);

    for(int i = m + 1; i<n; i++){
        if (pi[i] == m){
            int pos = i - 2 * m;
            cout << pos << endl;
        }
    }
}