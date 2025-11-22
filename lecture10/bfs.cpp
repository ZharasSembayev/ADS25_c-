#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
int n;

void BFS(int source){
    queue<int> q;
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    visited[source] = true;
    q.push(source);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int i=0; i<adj[v].size(); i++){
            int u = adj[v][i];
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

void bfs_with_distance(int source){
    queue<int> q;
    int distance[MAXN];

    for(int i=0; i<n; i++){
        visited[i] = false;
        distance[i] = -1;
    }

    visited[source] = true;
    distance[source] = 0;
    q.push(source);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<adj[v].size(); i++){
            int u = adj[v][i];
            if(!visited[u]){
                visited[u] = true;
                distance[u] = distance[v] + 1;
                q.push(u);
            }
        }
    }
    cout << "Distances from vertex: "<< source << " to " << ":" << endl;
    for(int i=0; i<n; i++){
        cout << "vertex: " << i << " ";
        if(distance[i] == -1){
            cout << "unreachable" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

void bfs_with_path(int source, int target){
    queue<int> q;
    int parent[MAXN];
    for(int i=0; i<n; i++){
        visited[i] = false;
        parent[i] = -1;
    }

    visited[source] = true;
    q.push(source);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(v == target){
            break;
        }

        for(int i=0; i<adj[v].size(); i++){
            int u = adj[v][i];
            if(!visited[u]){
                visited[u] = true;
                parent[u] = v;
                q.push(u);
            }
        }
    }
    if(!visited[target]){
        cout << "No path exists" << endl;
        return;
    }

    vector<int> path;
    int curr = target;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    cout << source << " to " << target << ": ";
    for(int i=0; i<path.size(); i++){
        cout << path[i];
        if(i < path.size() - 1){
            cout << " -> ";
        }
    } 
    cout << endl;
}