#include <iostream>
using namespace std;

struct Node {
    int v;
    Node* next;
};

int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        Node* node = new Node {x, nullptr};
        if (!head){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    Node* curr = head;
    while (curr && curr->next){
        curr->next =curr->next->next;
        curr = curr->next;
    }
    curr = head;
    while (curr) {
        cout << curr->v << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}