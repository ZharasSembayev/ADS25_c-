#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), v2(m);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int j = 0; j < m; j++) cin >> v2[j];

    vector<int> result;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i] == v2[j]) {
                result.push_back(v[i]);
                v2[j] = -1;
                break;
            }
        }
    }

    sort(result.begin(), result.end());

    for (int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}