//prevents header file from being processed twice
#ifndef LIST_H_
#define LIST_H_

extern void push(Node* head, void* data);

extern Node* get(Node* head, void* data);

extern Node* sort(Node* head, void* data);

extern void print(Node* head);

struct Node {
public:
  int count;
  void* data;
  Node *next;
};

#endif
