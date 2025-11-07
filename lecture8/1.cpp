#include <iostream>
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

int main(){
    cout << get_hash("hello") << endl;
    return 0;
}