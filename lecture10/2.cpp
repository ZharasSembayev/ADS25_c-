#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
int n;

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DirectedEdge(int u, int v){
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

void PrintList(){
    cout << "Adjacency List:" << endl;
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
int main() {
    n = 4;  // Number of vertices

    // Add edges
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    PrintList();

    // Print neighbors of vertex 0
    cout << "\nNeighbors of vertex 0: ";
    for (int i = 0; i < adj[0].size(); i++) {
        cout << adj[0][i] << " ";
    }
    cout << endl;

    return 0;
}