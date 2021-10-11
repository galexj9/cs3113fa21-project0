#include <stdlib.h>
#include <string.h>
#include "list.h"

/* The Nodes construct a singly-linked list.
** Node { int count; char* data; int dataLen; Node* next; }; */

//add a new node to the end of a list
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
  Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = a->data;
	temp->count = a->count;
	temp->dataLen = a->dataLen;
	
	a->data = b->data;
	a->count = b->count;
	a->dataLen = b->dataLen;

	b->data = temp->data;
	b->count = temp->count;
	b->dataLen = temp->dataLen;
	free(temp);
}

//returns a new list sorted in descending order by count using max sort
Node* sort(Node* list) {
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
	return list;
}

//return the Node pointer with given data
Node* get(Node* head, char* data, int dataLen) {
  Node* travel = head;
  while(travel) {
    if(travel->dataLen == dataLen &&
				0 == memcmp(travel->data, data, dataLen))
			break;
    travel = travel->next;
  }
  return travel;
}
