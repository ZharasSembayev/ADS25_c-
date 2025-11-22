#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;
int adj[maxn][maxn];
int n;

void addEdge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void addDirectedEdge(int u, int v){
    adj[u][v] = 1;
}
void addWeightedEdge(int u, int v, int weight){
    adj[u][v] = weight;
    adj[v][u] = weight;
}
bool hasEdge(int u, int v){
    return adj[u][v] != 0;
}

void printMatrix(){
    cout << "AdjacencyMatrix:" << endl;
    cout << "   ";
    for(int i=0; i<n; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << i << " [";
        for(int j=0; j<n; j++){
            cout << adj[i][j];
            if(j < n-1){
                cout << " ";
            }
        }
        cout << "]" << endl;
    }
}
