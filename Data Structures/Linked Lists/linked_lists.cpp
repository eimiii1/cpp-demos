#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void insertAtBeginning(Node*& head, string value);
void print(Node* head);

int main() {
    Node* head = nullptr;
    insertAtBeginning(head, "Philip");
}

void insertAtBeginning(Node*& head, string value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}