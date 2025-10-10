#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int d;
    Node* next;
    Node* prev;
    Node(int d){
        this->d = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList{
    public:
    Node *tail, *front;

    LinkedList(){
        tail = nullptr;
        front = nullptr;
    }

    void push_back(int d){
        Node* node = new Node(d);
        if(tail == nullptr){
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    void push_front(int d){
        Node* node = new Node(d);
        if(front == nullptr){
            front = node;
            tail = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }
    void pop_back(){
        if (tail != nullptr){
            tail = tail->prev;
            if (tail != nullptr){
                tail->next = nullptr;
            } else {
                front = nullptr;
            }
        }
    }

    void pop_front(){
        if (front != nullptr){
            front = front->next;
            if(front != nullptr){
                front->prev = nullptr;
            } else {
                tail = nullptr;
            }
        }

    }

    void deleteNode(Node* node){
        if (node == tail){
            pop_back();
        }
        else if (node == front){
            pop_front();
        }
        else {
            Node* a = node->prev;
            Node* b = node-> next;
            a->next = b;
            b->prev = a;
        }
    }

    void print(){
        Node* node = front;
        while (node != nullptr){
            cout << node->d << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node* find_node(int d){
        Node *node = front;
        while( node != nullptr){
            if (node->d == d)
                return node;
            node = node->next;
        }
        return nullptr;
    }

    void insert_node (Node* node1, int d){
        Node* node = new Node(d);
        if (node1 == tail){
            push_back(d);
        }
        else {
            Node* node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }
};

int main(){
    LinkedList* ll = new LinkedList();
    ll->push_back(5);
    ll->push_back(6);
    ll->push_back(7);
    ll->push_back(8);
    ll->push_back(9);
    ll->push_back(10);
    ll->push_front(11);
    ll->push_front(12);
    ll->push_front(13);
    ll->push_front(14);
    ll->push_front(15);

    ll->print();
    cout << ll->front->d << " " << ll->tail->d << endl;

    ll->pop_back();
    ll->pop_front();
    cout << ll->front->d << " " << ll->tail->d << endl;
}

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}