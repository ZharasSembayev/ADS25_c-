#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int u, v;
    int w;
};

const int maxn = 1000;
Edge edges[maxn];
int count = 0;
int n;

void addEdge(int u, int v, int w = 1){
    edges[count].u = u;
    edges[count].v = v;
    edges[count].w = w;
    count++;
}

void printEdges(){
    cout << "EdgeList:" << endl;
    for(int i=0; i<count; i++){
        cout << "(" << edges[i].u << "," << edges[i].v;
        if(edges[i].w != 1){
            cout << ", " << edges[i].w;
        }
        cout << ")" << endl;
    }
}    