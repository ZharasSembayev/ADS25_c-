#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int val){
        key = val;
        left = right =nullptr;
    }
};

class bst{
    public:
    Node* root;
    map<int, Node*> m;
    bst(){
        root = nullptr;
    }
    void build(int n){
        for(int i=0; i<n-1; i++){
            int x, y, z;
            cin >> x >> y >> z;
            if(!m[x]){
                m[x] = new Node(x);
            }
            if(!m[y]){
                m[y] = new Node(y);
            }
            if (z == 0){
                m[x]-> left = m[y];
            } else {
                m[x]->right = m[y];
            }
        }
        root = m[1];
    }
    void bfs(){
        queue<Node*> q;
        q.push(root);
        int maxwidth = 0;
        while(!q.empty()){
            int size = q.size();
            maxwidth = max(maxwidth, size);
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr-> right);
                }
            }
        }
        cout << maxwidth << endl;
    }

};

int main(){
    int n;
    cin >> n;
    bst tree;
    tree.build(n);
    tree.bfs();
    return 0;
}