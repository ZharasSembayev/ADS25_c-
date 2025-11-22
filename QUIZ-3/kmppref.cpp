#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function_naive(string s){
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
}