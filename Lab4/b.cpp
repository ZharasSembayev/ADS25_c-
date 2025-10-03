#include <iostream>
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
    BST(){
        root = nullptr;
    }

    Node* insert(Node* node, int key){
        if(node == nullptr){
            return new Node(key);
        }
        if(key < node->key){
            node->left = insert(node->left, key);
        } else if (key> node->key){
            node->right = insert(node->right, key);
        }
        return node;
    }

    void insert(int key){
        root = insert(root, key);
    }

    Node* search(Node* node, int key){
        if (node == nullptr || node->key == key){
            return node;
        }
        else if (key < node->key){
            return search(node->left, key);
        }
        else{
            return search(node->right, key);
        }
    }

    int countnodes(Node* node){
        if (node == nullptr){
            return 0;
        }
        return 1 + countnodes(node->left) + countnodes(node->right);
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    int x;
    cin >> x;
    Node* node = tree.search(tree.root, x);
    if(node != nullptr){
        cout << tree.countnodes(node) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}