#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int adj[MAXN][MAXN];
int n;

void addEdge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void addDirectedEdge(int u, int v){
    adj[u][v] = 1;
}

void addWeightedEdge(int u, int v, int w){
    adj[u][v] = w;
    adj[v][u] = w;
}

bool hasEdge(int u, int v){
    return adj[u][v] != 0;
}

void printMatrix(){
    cout << "Adjacency Matrix:" << endl;
    cout << "   ";
    for(int i=0; i<n; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << i << " [";
        for(int j=0; j<n; j++){
            cout << adj[i][j];
            if(j<n-1){
                cout << " ";
            }
        }
        cout << "]" << endl;
    }

}

int main(){
    n = 4;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj[i][j] = 0;
        }
    }
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);

    printMatrix();
    cout << "\nNeighbors of vertex 0: ";
    for (int i = 0; i < n; i++) {
        if (adj[0][i] != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}