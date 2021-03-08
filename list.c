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
  if(head->data == 0) {
    head = newNode;
  } else {
    Node* travel = head;
    while(travel->next != NULL)
      travel = travel->next;
    travel->next = newNode;
  }
  return head;
} 

//removes a given node from a list
Node* pop(Node* head, Node* del) {
  if(head->data == del->data)
    return head->next;

  //find the node previous the one to remove
  Node* travel = head;
  while(travel->next != del)
    travel = travel->next;
  //remove the Node
  travel->next = travel->next->next;

  return head;
}

//returns a new list sorted in descending order by count using max sort
Node* sort(Node* list) {
  Node* sorted = (Node *) malloc(sizeof(Node));
  Node* max;
  Node* travel;
  
  //loop thru the unsorted list until it is empty
  while(list != NULL) {
    travel = list;
    max = travel;
    //find the largest unsorted element
    while(travel != NULL) {
      if(travel->count > max->count)
        max = travel;
      travel = travel->next;
    }

    //remove the largest element from the unsorted list
    list = pop(list, max);
    //add it to the end of the sorted list
    sorted = push(sorted, max);
  }

  return sorted;
}

//return the Node pointer with given data
Node* get(Node* head, wint_t data) {
  Node* travel = head;
  while(travel != NULL) {
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
        printf("\%lc", travel->data);
        printf("->%d\n", travel->count);
    }
    travel = travel->next;
  }
}
