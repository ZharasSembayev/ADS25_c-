#include <iostream>
#include <string>
using namespace std;

struct Node {
    string w;
    Node* next;
};

Node* rotate(Node* head, int k, int n){
    if (!head || k%n == 0){
        return head;
    }
    k = k % n;
    Node* curr = head;
    for (int i=1; i<k; i++){
        curr = curr ->next;
    }
    Node* newHead = curr->next;
    curr->next = nullptr;
    Node* tail = newHead;
    while(tail->next){
        tail = tail-> next;
    }
    tail->next = head;
    return newHead;
}
int main(){
    int n,k;
    cin >> n >> k;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        Node* node = new Node{s, nullptr};
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    head = rotate(head, k, n);
    Node* curr = head;
    while(curr) {
        cout << curr ->w << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}