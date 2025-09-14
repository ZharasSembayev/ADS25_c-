#include <iostream>
#include <string>
using namespace std;

string f(string s){
    string r = " ";
    for (char c : s){
        if (c == '#'){
            if (!r.empty()) r.pop_back();
        } else{
            r.push_back(c);
        }
    }
    return r;

}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if (f(s1) == f(s2)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}