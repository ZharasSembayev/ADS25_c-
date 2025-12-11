#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
int n;

void DFS(int v){
    visited[v] = true;
    cout << v << " ";
    for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];
        if(!visited[u]){
            DFS(u);
        }
    }
}

int main(){
    int n = 6;
    for(int i=0;i<n; i++){
        visited[i] = false;
    }
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(4);
    adj[4].push_back(1);
    adj[2].push_back(5);
    adj[5].push_back(2);
    DFS(0);
}