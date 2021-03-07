//prevents header file from being processed twice
#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
  int count;
  void* data;
  struct Node* next;
} Node;

extern void push(Node* head, void* data);

extern Node* get(Node* head, void* data);

extern Node* sort(Node* head, void* data);

extern void print(Node* head);

#endif
