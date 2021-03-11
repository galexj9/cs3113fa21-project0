#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* This file, along with list.h, contains functions for using the
** Node struct.  The Nodes construct a singly-linked list.
** Node { int count; wint_t data; struct Node* next; };
*/

//add a new node with data to the end of a list
Node* push(Node* head, Node* newNode) {
  if(head == NULL)
    return newNode;

  Node* travel = head;
  while(travel->next)
    travel = travel->next;
  travel->next = newNode;
  return head;
}

//swaps the data of two nodes
void swap(Node* a, Node* b){
  Node* temp = (Node *) malloc(sizeof(Node));
  temp->count = a->count;
  temp->data = a->data;

  a->count = b->count;
  a->data = b->data;

  b->count = temp->count;
  b->data = temp->data;

  free(temp);
}

//returns a new list sorted in descending order by count using max sort
void sort(Node* list) {
  Node* front = list;
  Node* travel, *max;

  while(front->next) {
    max = front;
    travel = front->next;
    while(travel) {
      if(travel->count > max->count)
        max = travel;
      travel = travel->next;
    }
    swap(front, max); //move the max el to the end of the sorted section
    front = front->next; //move down from the sorted section
  }
}

//return the Node pointer with given data
Node* get(Node* head, char* data) {
  Node* travel = head;
  while(travel) {
    if(*travel->data == *data)
      break;
    travel = travel->next;
  }
  return travel;
}

//prints out the unicode chars followed by an arrow and their occurance count
//ex: "a->4"
void print(Node* head) {
  Node* travel = head;
  while(travel != NULL) {
    fwrite(travel->data, sizeof(travel->data), 1, stdout);
    printf("->%d\n", travel->count);

    travel = travel->next;
  }
}
