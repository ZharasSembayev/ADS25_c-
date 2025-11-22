#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> adj[maxn];
int n;

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addDirectededge(int u, int v){
    adj[u].push_back(v);
}

bool hasEdge(int u, int v){
    for(int i=0; i<adj[u].size(); i++){
        if(adj[u][i] == v){
            return true;
        }
    }
    return false;
}

void printList(){
    cout << "AdjacencyList: " << endl;
    for(int i=0; i<n; i++){
        cout << i << ": [";
        for(int j=0; j<adj[i].size(); j++){
            cout << adj[i][j];
            if(j < adj[i].size() - 1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}