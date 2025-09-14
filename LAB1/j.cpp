#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque<int> d;
    char c;
    while (cin >> c){
        if (c == '!'){
            break;
        } else if (c == '+'){
            int x;
            cin >> x;
            d.push_front(x);
        } else if (c == '-'){
            int x;
            cin >> x;
            d.push_back(x);
        } else if (c == '*'){
            if (d.empty()){
                cout << "error" << endl;
            }
            else if (d.size() == 1){
                int v = d.front();
                cout << v + v << endl;
                d.pop_front();
            }
            else {
                int f = d.front();
                int l = d.back();
                cout << f + l << endl;
                d.pop_front();
                d.pop_back();
            }
        }
    }
    return 0;
}