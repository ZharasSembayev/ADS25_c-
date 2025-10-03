#include <iostream>
#include <algorithm>
#include <vector>
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
        } else if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void transform(Node* node, int &sum) {
        if (!node) return;
        transform(node->right, sum);
        sum += node->key;
        node->key = sum;
        transform(node->left, sum);
    }

    void inOrder(Node *node, vector<int> &v) {
        if (!node) return;
        inOrder(node->right, v);
        v.push_back(node->key);
        inOrder(node->left, v);
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
    int sum = 0; 
    tree.transform(tree.root, sum);

    vector<int> v1;
    tree.inOrder(tree.root, v1);

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i];
        if (i != v1.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}