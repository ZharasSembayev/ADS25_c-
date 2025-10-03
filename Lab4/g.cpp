#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

class bst {
public:
    Node* root;
    bst() {
        root = nullptr;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) { 
            node->right = insert(node->right, key);
        }
        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    int diameterUtil(Node* node, int &maxDiam) {
        if (node == nullptr)
            return 0;
        int lh = diameterUtil(node->left, maxDiam);
        int rh = diameterUtil(node->right, maxDiam);
        maxDiam = max(maxDiam, lh + rh + 1);
        return 1 + max(lh, rh);
    }

    int diameter() {
        int maxDiam = 0;
        diameterUtil(root, maxDiam);
        return maxDiam;
    }
};

int main() {
    int n;
    cin >> n;
    bst tree;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.insert(x);
    }
    cout << tree.diameter() << endl;
    return 0;
}
