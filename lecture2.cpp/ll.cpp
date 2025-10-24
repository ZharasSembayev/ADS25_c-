#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Linkedlist{
    public:
    Node* head;
    Linkedlist(){
        head = nullptr;
    }
    void insert(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int value){
        if(head == nullptr) return;
        if(head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while(curr->next != nullptr && curr->next->data != value){
            curr = curr->next;
        }
        if(curr->next != nullptr){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "null";
    }
};

int main(){
    Linkedlist list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.print();
    return 0;
}