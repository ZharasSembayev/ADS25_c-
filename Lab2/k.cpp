#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        queue<char> q;
        unordered_map<char, int> u;
        for (int i=0; i<n; i++){
            char c;
            cin >> c;
            u[c]++;
            q.push(c);
            while(!q.empty() && u[q.front()] > 1){
                q.pop();
            }
            if (q.empty()){
                cout << -1 << " ";
            } else {
                cout << q.front() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}