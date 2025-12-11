#include <bits/stdc++.h>
using namespaace std;

struct Edge{
    int u, v, w;
};

int main(){
    const long long INF  = 4e18;
    int n, m, s;
    cin >> n >> m >> s;
    vector<Edge> edges(m);
    for(auto &e : edges){
        cin >> e.u >> e.v >> e.w;
    }
    vector<long long> dist(n, INF);
    dist[s] = 0;

    for(int i=0; i<n-1; i++){
        bool changed = false;
        for(auto [u,v,w] : edges){
            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if(!changed){
            break;
        }
    }
    bool has_neg_cycle = false;
    for(auto [u,v,w] : edges){
        if(dist[u] != INF && dist[u] + w < dist[v]){
            has_neg_cycle = true;
            break;
        }
    }
}