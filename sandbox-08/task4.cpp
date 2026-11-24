#include <iostream>

struct Node {
  int value;
  Node *next;
};

int main() {
  Node *head = nullptr;
  Node *tail = nullptr;
  int length = 0;

  for (int v = 1; v <= 3; ++v) {
    Node *node = new Node{v, nullptr};
    if (tail == nullptr) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;
    length = length + 1;
  }

  for (Node *n = head; n != nullptr; n = n->next) {
    std::cout << n->value;
    if (n->next != nullptr)
      std::cout << ' ';
  }
  std::cout << '\n' << length << '\n';

  while (head != nullptr) {
    Node *next = head->next;
    delete head;
    head = next;
  }
}