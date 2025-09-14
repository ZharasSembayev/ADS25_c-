#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> s1;
    for (char c : s){
        if (!s1.empty() && s1.top() == c){
            s1.pop();
        }
        else {
            s1.push(c);
        }
    }
    if (s1.empty()){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}