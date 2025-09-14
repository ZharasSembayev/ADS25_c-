#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int limit = 100000;
    vector<int> v;
    for (int i = 2; i <= limit; i++) {
        bool isprime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) {
            v.push_back(i);
        }
    }
    vector<int> v1;
    for (int i = 0; i < v.size(); i++) {
        int indx = i + 1; 
        if (indx < 2) continue;

        bool p = true;
        for (int j = 2; j * j <= indx; j++) {
            if (indx % j == 0) {
                p = false;
                break;
            }
        }
        if (p) {
            v1.push_back(v[i]);
        }
    }

    cout << v1[n-1] << endl;

    return 0;
}