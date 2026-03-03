#include <iostream>
#include <vector>

struct Node {
  std::string data;
  Node *next;
};

void insertAtBeginning(Node *&head, std::string name);
void printList(Node *head);

int main() {
  std::vector<std::string> names = {"Philip", "Jeanclaude Kalabaw", "John", "Junel", "Maria"};
  Node *head = nullptr;
  
  for (std::string n : names) {
    insertAtBeginning(head, n);
  }
  
  printList(head);
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
    std::cout << "\033[34m" << temp->data << "\033[0m";
    if (temp->next != nullptr) std::cout << " -> ";
    temp = temp->next;
  }
}