#include <iostream>
#include <string>
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
class BST{
    public:
    Node* root;
    BST (){
        root = nullptr;
    }
    Node* insert(Node* node,int key){
        if (node == nullptr){
            return new Node(key);
        }
        if(key < node->key){
            node->left = insert(node->left, key);
        } else if (key > node->key){
            node->right = insert(node->right, key);
        }
        return node;
    }
    void insert(int key){
        root = insert(root, key);
    }

    bool checkpath(string path){
        Node* curr = root;
        for(char c : path){
            if(curr == nullptr){
            return false;
            }
            if(c == 'L'){
                curr = curr->left;
            } else if ( c == 'R'){
                curr = curr->right;
            }
        }
        return curr != nullptr;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    BST tree;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    for(int i=0; i<m; i++){
        string path;
        cin >> path;
        if(tree.checkpath(path)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}