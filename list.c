#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "list.h"

/* This file, along with list.h contains functions for using the
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

//returns a new list sorted in descending order by count using insertion sort
void sort(Node* list) {
  Node* start = list;
  Node* travel, *max;

  while(start->next) {
    max = start;
    travel = start->next;
    while(travel) {
      if(travel->count > max->count)
        max = travel;
      travel = travel->next;
    }
    swap(start, max); //move the max el to the top of the list
    start = start->next; //move on down
  }
}

//return the Node pointer with given data
Node* get(Node* head, wint_t data) {
  Node* travel = head;
  while(travel) {
    if(travel->data == data)
      break;
    travel = travel->next;
  }
  return travel;
}

//prints out a list with its data
void print(Node* head) {
  Node* travel = head;
  while(travel != NULL) {
    //handle line breaks and spaces separately
    switch(travel->data) {
      case '\n':
        printf("\\n->%d\n", travel->count);
        break;
      case ' ':
        printf("\' \'->%d\n", travel->count);
        break;
      default:
        printf("%lc", travel->data);
        printf("->%d\n", travel->count);
    }
    travel = travel->next;
  }
}
