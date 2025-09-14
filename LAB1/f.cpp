#include <iostream>
using namespace std;

bool IsSimpleNum(int x ){
    if (x < 2) return false;
    for (int i=2; i*i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int count = 0;
    int cnum = 1;
    while (count < n){
        cnum++;
        if(IsSimpleNum(cnum)) count++;
    }
    cout << cnum << endl;
    return 0;
}