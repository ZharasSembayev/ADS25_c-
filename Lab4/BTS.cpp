#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node(int value){
        key = value;
        left = right =nullptr;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = nullptr;
    }
    Node* insert(Node* node, int key){
        if (node == nullptr){
            return new Node(key);
        }else if (key < node->key){
            node->left = insert (node->left, key);
        } else if (key > node->key){
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
        } else if (key < node->key){
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }
    Node* findmin(Node* node){
        if (node == nullptr){
            return node;
        }
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
    Node* findmax(Node* node){
        if(node == nullptr){
            return node;
        }
        while(node->right != nullptr){
            node = node->right;
        }
        return node;
    }
    Node* deleteNode(Node* node, int key){
        if (node == nullptr){
            return node;
        }
        if(key < node->key){
            node->left = deleteNode(node->left, key);
        } else if ( key > node->key){
            node ->right = deleteNode(node->right, key);
        } else {
            if(node->right == nullptr && node->left == nullptr){
                delete node;
                node = nullptr;
            }
            else if(node->left == nullptr){
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if(node->right == nullptr){
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* temp = findmin(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }
        return node;
    }
    void remove(int key){
        root = deleteNode(root, key);
    }

    void inorder(Node* node){
        if(node != nullptr){
            inorder(node->left);
            cout << node->key << " " ;
            inorder(node->right);
        }
    }

    void priorder(){
        inorder(root);
        cout << endl;
    }
};

int main(){
    BST* bst= new BST();
    bst->root = bst->insert(bst->root, 1);
    bst->root = bst->insert(bst->root, 2);
    bst->root = bst->insert(bst->root, 3);
    bst->root = bst->insert(bst->root, 16);
    bst->root = bst->insert(bst->root, 13);
    bst->root = bst->insert(bst->root, 12);
    bst->root = bst->insert(bst->root, 14);
    bst->root = bst->insert(bst->root, 9);
    bst->root = bst->insert(bst->root, 8);
    bst->root = bst->insert(bst->root, 10);  
    bst->root = bst->insert(bst->root, 10);  
    bst->root = bst->insert(bst->root, 17);

    cout << "Inorder (sorted): " ;
    bst->inorder(bst->root);
    cout << endl;

    Node* node_min =bst->findmin(bst->root);
    Node* node_max = bst->findmax(bst->root);
    cout << "MIN: " << node_min->key << ", MAX: " << node_max->key << endl;

    Node* found = bst->search(bst->root, 10);
    if (found){
        cout << "Found: " << found->key << endl;
    } else {
        cout << "Not found" << endl;
    }
}
