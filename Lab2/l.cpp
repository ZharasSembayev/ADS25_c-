#include <iostream>
using namespace std;

struct Node {
    int n;
    Node* next;
};
int findmaxsum(Node* head){
    if (!head) {
        return 0;
    }
    int cs = head->n;
    int ms = head->n;
    Node* curr = head->next;
    while(curr){
        cs = max(curr->n, cs + curr->n);
        ms = max(ms, cs);
        curr = curr->next;
    }
    return ms;
}
int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        Node* node = new Node{x, nullptr};
        if (!head){
            head = node;
            tail = node;
        } else {
            tail -> next = node;
            tail = node;
        }
    }
    cout << findmaxsum(head) << endl;
    return 0;
}