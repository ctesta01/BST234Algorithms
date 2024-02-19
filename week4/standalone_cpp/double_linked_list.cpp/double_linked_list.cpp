#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node* next;
  Node* prev;
};

class LinkedList {
public:
  Node* head;
  Node* tail;
  LinkedList() {
    head = NULL;
    tail = NULL;
  }
  void add(int value) {
    Node* newnode = new Node();
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = tail;
    if (tail!=NULL) {
      tail->next = newnode;
    }
    tail = newnode;
    if (head==NULL) {
      head = newnode;
    }
  }
  void print() {
    Node* current = head;
    while (current!=NULL) {
      cout << current->value << endl;
      current = current->next;
    }
  }
};

int main() {
  LinkedList list;
  list.add(5);
  list.add(6);
  list.add(7);
  list.print();
}
