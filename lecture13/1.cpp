#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>> g(n);
    for(int i=0; i<n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v , w});
    }

    vector<int> d(n, INF), p(n , -1);
    vector<char> used(n, false);
    d[s] = 0;
    for(int i=0; i<n; i++){
        int v = -1;
        for(int j=0; j<n; j++){
            if(!used[j] && (v == -1 || d[j] < d[v])){
                v = j;
            }
        }
        if(v == -1 || d[v] == INF){
            break;
        }
        used[v] = true;
        for(auto [to, len] : g[v]){
            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}