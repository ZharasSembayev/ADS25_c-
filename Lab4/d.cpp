#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int val){
        key = val;
        left = right = nullptr;
    }
};

class bst{
    public:
    Node* root;
    bst(){
        root = nullptr;
    }
    Node* insert(Node* node, int key){
        if(node == nullptr){
            return new Node(key);
        } else if (key < node->key){
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }
    void insert(int key){
        root = insert(root, key);
    }
    void bfslsum(){
        if (root == nullptr){
            return;
        }
        queue<Node*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int lvlsum =0;
            for(int i=0; i<size; i++){
                Node* curr = q.front();
                q.pop();
                lvlsum += curr->key;

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

            }
            v.push_back(lvlsum);
        }
        cout << v.size() << endl;
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }


};

int main(){
    int n;
    cin>>n;
    bst tree;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        tree.insert(x);
    }
    tree.bfslsum();
    return 0;
}