//prevents header file from being processed twice
#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
  int count;
  char* data;
  int dataLen;
  struct Node* next;
} Node;

//push a node to the end of a list
extern Node* push(Node* head, Node* newNode);

//return a pointer to the first node in the list with given data
extern Node* get(Node* head, char* data, int dataLen);

//sorts the list in descending order using mergesort
extern void sort(Node** list);
#endif
