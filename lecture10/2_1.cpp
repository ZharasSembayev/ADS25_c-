#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<pair<int, int>> adj[MAXN];
int n;

void addWeightedEdge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void PrintWeightedList(){
    cout << "WeightedList:" << endl;
    for(int i=0; i<n; i++){
        cout << i << ": [";
        for(int j = 0; j<adj[i].size(); j++){
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")";
            if(j < adj[i].size()-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    n = 4;

    addWeightedEdge(0, 1, 5);
    addWeightedEdge(0, 3, 3);
    addWeightedEdge(1, 2, 7);
    addWeightedEdge(2, 3, 2);

    PrintWeightedList();

    return 0;
}