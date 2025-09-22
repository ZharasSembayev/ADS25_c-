#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    list<string> l;
    string s;
    while(cin >> s){
        if (s == "add_front"){
            string b;
            cin >> b;
            l.push_front(b);
            cout << "ok" << endl;
        } else if (s == "add_back"){
            string b;
            cin >> b;
            l.push_back(b);
            cout << "ok" <<endl;
        } else if (s == "erase_front"){
            if (l.empty()){
                cout << "error" << endl;
            } else {
                cout << l.front() << endl;
                l.pop_front();
            }
        } else if (s == "erase_back"){
            if(l.empty()){
                cout << "error" << endl;
            } else {
                cout << l.back() << endl;
                l.pop_back();
            }
        } else if(s == "front") {
            if (l.empty()) {
                cout << "error" << endl;
            } else {
                cout << l.front() << endl;
            }
        } else if (s == "back"){
            if (l.empty()){
                cout << "error" << endl;
            } else {
                cout << l.back() << endl;
            }
        } else if(s == "clear"){
            l.clear();
            cout << "ok" << endl;
        } else if(s == "exit"){
            cout << "goodbye" << endl;
            break;
        }

    }
    return 0;
}