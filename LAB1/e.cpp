#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> b, n;
    for (int i=0; i<5; i++){
        int c;
        cin >> c;
        b.push(c);
    }
    for (int i=0; i<5; i++){
        int c;
        cin >> c;
        n.push(c);
    }
    int m=0; 
    int max_m = 1000;
    while (!b.empty() && !n.empty() && m < max_m){
        m++;
        int b_c = b.front();
        int n_c = n.front();
        b.pop();
        n.pop();
        if ((b_c > n_c && !(b_c == 9 && n_c == 0)) || (b_c == 0 && n_c == 9)){
            b.push(b_c);
            b.push(n_c);
        } else {
            n.push(b_c);
            n.push(n_c);
        }
    }
    if (b.empty()){
        cout << "Nursik " << m << endl;
    } else if (n.empty()){
        cout << "Boris" << m << endl;
    }
    else {
        cout << "blin nichya" << endl;
    }
    return 0;
}