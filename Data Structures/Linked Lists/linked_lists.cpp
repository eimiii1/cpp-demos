#include <iostream>

struct Node {
  std::string data;
  Node *next;
};

void insertAtBeginning(Node *&head, std::string name);
void printList(Node *head);

int main() {
  Node *head = nullptr;
  insertAtBeginning(head, "Philip");
}

void insertAtBeginning(Node *&head, std::string name) {
  Node *newNode = new Node();
  newNode->data = name;
  newNode->next = head;
  head = newNode;
}

void printList(Node *head) {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data;
    if (temp->next != nullptr) std::cout << " -> ";
    temp = temp->next;
  }
}