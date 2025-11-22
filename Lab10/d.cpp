#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, INF);
    queue<int> bfs;

    while (q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            if (dist[v] != 0) {
                dist[v] = 0;
                bfs.push(v);
                while (!bfs.empty()) {
                    int u = bfs.front();
                    bfs.pop();

                    for (int nxt : adj[u]) {
                        if (dist[nxt] > dist[u] + 1) {
                            dist[nxt] = dist[u] + 1;
                            bfs.push(nxt);
                        }
                    }
                }
            }
        }
        else {
            if (dist[v] == INF) cout << -1 << "\n";
            else cout << dist[v] << "\n";
        }
    }

    return 0;
}