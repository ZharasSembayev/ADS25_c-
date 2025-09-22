#include <iostream>
using namespace std;

struct Node{
    int d;
    Node* next;
};
Node* insNode(Node* head, int d, int pos){
    Node* newNode = new Node();
    newNode->d = d;
    newNode->next = nullptr;

    if (pos == 0){
        newNode->next = head;
        return newNode;
    }
    Node* curr = head;
    for(int i=0; i<pos -1; i++){
        curr =curr->next;
    }
    newNode-> next = curr->next;
    curr->next = newNode;
    return head;
}
int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        Node* node = new Node();
        node-> d = x;
        node->next = nullptr;
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    int d, pos;
    cin >> d >> pos;
    head = insNode(head, d, pos);
    Node* curr = head;
    while (curr) {
        cout << curr->d << " ";
        curr = curr->next;
    }
    cout << endl;
}