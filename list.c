#include <stdio.h>
#include "list.h"

//add a new node with data to the end of a list
void push(Node* head, void* data) {
  Node* newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;

  Node* travel = head;
  while(travel->next != NULL) {
    travel = travel->next;
  }
  travel->next = newNode;
}

//return the Node pointer with given data
Node* get(Node* head, void* data) {
  Node* travel = head;
  while(travel->next != NULL) {
    travel = travel->next;
    if(travel->data = data){
      return travel;
    }
  }
  return NULL;
}

//returns a new list sorted in descending order by count
Node* sort(Node* head) {
  return head;
}

//prints out a list with its data
void print(Node* head) {
  Node* travel = head;
  char character = 'a';
  printf("%c -> %d", character, travel->count);
}
