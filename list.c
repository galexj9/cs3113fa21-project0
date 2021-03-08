#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "list.h"

//add a new node with data to the end of a list
Node* push(Node* head, wint_t data) {
  Node* newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;

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

Node* pop(Node* head, wint_t data) {
  if(head->data == data)
    return NULL;

  //find the node before the one to remove
  Node* travel = head;
  while(travel->next->data != data)
    travel = travel->next;
  //remove the Node
  travel->next = travel->next->next;

  return head;
}
//returns a new list sorted in descending order by count
//sorts using max sort
Node* sort(Node* list) {
  Node* sorted = (Node *) malloc(sizeof(Node));
  Node* max, *travel;
  //loop thru the unsorted list until it is empty
  while(list != NULL) {
    max = list;
    travel = list;
    //find the largest unsorted element
    while(travel != NULL) {
      if(travel->count > max->count)
        max = travel;
      travel = travel->next;
    }

    //remove the largest element from the unsorted list
    list = pop(list, max->data);
    //add it to the end of the sorted list
    sorted = push(sorted, max->data);
  }

  return sorted;
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
