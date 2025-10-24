#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = nullptr;
    }  
    Node* insert(Node* node, int data){
        if(node == nullptr){
            return new Node(data);
        }
        if(data <= node->data){
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void Inorder(Node* node){
        if(node == nullptr){
            return;
        }
        Inorder(node->left);
        cout<<node->data << " ";
        Inorder(node->right);
    }

    Node* findmin(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }

    Node* findmax(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        while(node->right != nullptr){
            node = node->right;
        }
        return node;
    }

    Node* search(Node* node, int data){
        if(node == nullptr || node->data == data){
            return node;
        }
        if(data < node->data){
            return search(node->left, data);
        } else {
            return search(node->right, data);
        }
    }
    Node* deleteNode(Node* node, int data){
        if(node == nullptr){
            return nullptr;
        }
        if(data < node->data){
            node->left = deleteNode(node->left, data);
        } else if (data > node->data){
            node->right = deleteNode(node->right, data);
        }
        else {
            if(node->left == nullptr && node->right == nullptr){
                delete node;
                node = nullptr;
            }
            else if(node->left == nullptr){
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == nullptr){
                Node* temp = node;
                node = node->right;
                delete temp;
            }
            else {
                Node* tmp = findmax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data); 
            }
        }
        return node;

    }
};

int main(){
    BST tree;

}