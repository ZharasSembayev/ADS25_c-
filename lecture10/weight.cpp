#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;
vector<pair<int, int>> adj[maxn];
int n;

void addEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void printWeightedEdge(){
    cout << "WeightedEdge: " << endl;
    for(int i=0; i<n; i++){
        cout << i << ": [";
        for(int j=0; j<adj[i].size(); j++){
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")" ;
            if(j < adj[i].size() - 1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}