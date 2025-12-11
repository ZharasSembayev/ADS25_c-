#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long = 4e18;
    int n;
    cin >> n;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            int u,v,w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], 1ll * w);
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}