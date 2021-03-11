//prevents header file from being processed twice
#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
  int count;
  char* data;
  struct Node* next;
} Node;

//push a node to the end of a list
extern Node* push(Node* head, Node* newNode);

//return a pointer to the first node in the list with given data
extern Node* get(Node* head, char* data);

//sorts the list in descending order using max insertion sort
extern void sort(Node* head);

//prints a list to stdout in the form "char->count\n"
extern void print(Node* head);

#endif
