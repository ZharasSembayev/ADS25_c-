#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    int weight;
};

const int maxe = 1000;
Edge edges[maxe];
int edgecount = 0;
int n;

void addEdge(int u, int v, int weight = 1){
    edges[edgecount].u = u;
    edges[edgecount].v = v;
    edges[edgecount].weight = weight;
    edgecount++;
}

void printEdge(){
    cout << "EdgeList:" << endl;
    for(int i=0; i<edgecount; i++){
        cout << "("  << edges[i].u << "," << edges[i].v;
        if(edges[i].weight != 1){
            cout << ", " << edges[i].weight;
        }
        cout << ")" << endl;
    }
}