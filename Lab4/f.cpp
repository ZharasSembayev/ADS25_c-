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

class bst{
    public:
    Node* root;
    bst(){
        root = nullptr;
    }

    Node* insert(Node* node, int key){
        if (node ==  nullptr){
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

    int countTriangle(Node* node){
        if(node == nullptr){
            return 0;
        }
        int leftc = countTriangle(node->left);
        int rightc = countTriangle(node->right);
        int curr = (node->left != nullptr && node->right != nullptr);
        return leftc + rightc + curr;
    }
    int countTriangle(){
        return countTriangle(root);
    }
};

int main(){
    int n;
    cin >> n;
    bst tree;
    for(int i=0; i<n; i++){
        int x; 
        cin >> x; 
        tree.insert(x);
    }
    cout << tree.countTriangle() << endl;
    return 0;
}