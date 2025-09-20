#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    queue<int> S,K;
    for (int i=0; i < n; i++){
        if (s[i] == 'S'){
            S.push(i);
        } else {
            K.push(i);
        }
    }
    while (!S.empty() && !K.empty()){
        int i = S.front();
        S.pop();
        int j = K.front();
        K.pop();
        if (i < j){
            S.push(i + n);
        } else {
            K.push(j + n);
        }
    }
    if (S.empty()){
        cout << "KATSURAGI" << endl;
    } else {
        cout << "SAKAYANAGI" << endl;
    }
    return 0;
}