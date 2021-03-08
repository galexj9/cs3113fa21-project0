//prevents header file from being processed twice
#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
  int count;
  wchar_t data;
  struct Node* next;
} Node;

extern Node* push(Node* head, wchar_t data);

extern Node* get(Node* head, wchar_t data);

extern Node* sort(Node* head);

extern void print(Node* head);

#endif
