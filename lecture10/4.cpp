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

void addweightedEdge(int u, int v, int weight){
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
            if(j < n - 1){
                cout << " ";
            }
        }
        cout << "]" << endl;
    }
}

// #AdjacencyList:

const int Maxn = 100;
vector<int> adja[Maxn];
int n;

void addEdge(int u, int v){
    adja[u].push_back(v);
    adja[v].push_back(u);
}

void addDirectedEdge(int u, int v){
    adja[u].push_back(v);
}

bool hasEdge(int u, int v){
    for(int i=0; i<adja[u].size(); i++){
        if(adj[u][i] == v){
            return true;
        }
    }
    return false;
}

void printList(){
    cout << "AdjacencyList:" << endl;
    for(int i=0; i<n; i++){
        cout << i << ": [";
        for(int j=0; j<adja[i].size();j++){
            cout << adja[i][j];
            if(j < adja[i].size()-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

const int MAXN = 100;
vector<pair<int, int>> adjweight[MAXN];
int n;

void addWeightedEdge(int u, int v, int weight){
    adjweight[u].push_back({v, weight});
    adjweight[v].push_back({u, weight});
}

void printWeightedEdge(){
    cout << "Weighted Adjacency List:" << endl;
    for(int i=0; i<n; i++){
        cout << i << ": [";
        for(int j=0; j<adjweight[i].size(); j++){
            cout << "(" << adjweight[i][j].first << "," << adjweight[i][j].second << ")";
            if(j<adjweight[i].size()-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

struct Edge{
    int u, v;
    int weight;
};

const int MAXE = 1000;
Edge edges[MAXE];
int edgecount = 0;
int n;

void addEdge(int u, int v, int weight = 1){
    edges[edgecount].u = u;
    edges[edgecount].v = v;
    edges[edgecount].weight = weight;
    edgecount++;
}

void printEdge(){
    cout << "Edge List:" << endl;
    for(int i=0; i<edgecount; i++){
        cout << "(" << edges[i].u << ", " << edges[i].v;
        if(edges[i].weight != 1){
            cout << ", " << edges[i].weight;
        }
        cout << ")" << endl;
    }
}