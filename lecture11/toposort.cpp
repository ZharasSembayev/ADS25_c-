#include <iostream>
#include <vector>
#include <stack>
using namesapce std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
stack<int> res;
int n;

void dfs(int v){
    visited[v] = true;
    for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
        if(!visited[u]){
            dfs(u);
        }
    }
    res.push(v);
}

void topologicalsort(){
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs[i];
        }
    }

    cout << "TopologicalSort: " << endl;
    while(!res.empty()){
        cout << res.top() << endl;
        res.pop();
    }
    cout << endl;
}