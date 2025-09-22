#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l;
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        } else if ( n == 1){
            int x,p;
            cin >> x >> p;
            auto it = l.begin();
            advance(it, p);
            l.insert(it, x);

        } else if (n==2){
            int p;
            cin >> p;
            auto it = l.begin();
            advance(it, p);
            l.erase(it);
        } else if (n == 3){
            if (l.empty()){
                cout << -1;
            } else {
                for(int i : l){
                    cout << i << " ";
                }
            }
            cout << endl;
        } else if(n == 4){
            int p1, p2; 
            cin >> p1 >> p2;
            auto it = l.begin();
            advance(it, p1);
            int m = *it;
            l.erase(it);
            auto it2 = l.begin();
            advance(it2, p2);
            l.insert(it2, m);
        } else if(n == 5){
            l.reverse();
        } else if (n == 6){
            int x; cin >> x;
            while(x--){
                l.push_back(l.front());
                l.pop_front();
            }
        } else if (n==7){
            int x; cin >> x;
            while(x--){
                l.push_front(l.back());
                l.pop_back();
            }
        }
    }
    return 0;
}