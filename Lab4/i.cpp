#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int key;
    int count; 
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        count = 1;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            node->count++; 
        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, int key) {
        if (node == nullptr) return nullptr;

        if (key < node->key)
            node->left = remove(node->left, key);
        else if (key > node->key)
            node->right = remove(node->right, key);
        else {
            if (node->count > 1) {
                node->count--;  
                return node;
            }
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->count = temp->count;
            temp->count = 1;
            node->right = remove(node->right, temp->key);
        }
        return node;
    }

    void remove(int key) {
        root = remove(root, key);
    }

    int countKey(Node* node, int key) {
        if (node == nullptr) return 0;
        if (key < node->key) return countKey(node->left, key);
        if (key > node->key) return countKey(node->right, key);
        return node->count;
    }

    int countKey(int key) {
        return countKey(root, key);
    }
};

int main() {
    int q;
    cin >> q;
    BST tree;

    for (int i = 0; i < q; ++i) {
        string cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == "insert") {
            tree.insert(x);
        } else if (cmd == "delete") {
            tree.remove(x);
        } else if (cmd == "cnt") {
            cout << tree.countKey(x) << "\n";
        }
    }

    return 0;
}