#include <string.h> //memcmp()
#include "list.h"

/* The Nodes construct a singly-linked list.
** Node { int count; char* data; int dataLen; Node* next; }; */

//add a new node to the beginning of a list
Node* push(Node* head, Node* newNode) {
  newNode->next = head;
  return newNode;
}

//splits a Node* list in two for merge sorting
void split(Node* head, Node** front, Node** back) {
	Node* travel = head->next;
	Node* slow = head;
	*front = head;
	
	//travel moves twice for every 1 move slow makes
	//and stops when travel reaches the end so slow is mid-1
	while(travel != NULL) {
		travel = travel->next;
		if (travel != NULL) {
			travel = travel->next;
			slow = slow->next;
		}
	}
	//assign back to the mid element in the list and NULL terminate the front half
	*back = slow->next;
	slow->next = NULL;
}

//recursively move the largest first element of 2 lists to a new one
Node* merge(Node* front, Node* back) {
	if(front == NULL)
			return back; 
	else if (back == NULL)
			return front;

	Node* merged;
	//elements with the same count are added in order of first appearance
	//since new elements are added to the front, favor the one in back
	if(front->count > back->count) {
		merged = front;
		merged->next = merge(front->next, back);
	} else {
		merged = back;
		merged->next = merge(front, back->next);
	}
	return merged;
}

//recusrively splits and sorts a Node* list using merge sort
//uses double pointers so that the list pointer can be overwritten
void sort(Node** list) {
	Node*	head = *list;
	Node* front, *back;

	if (head == NULL || head->next == NULL)
		return;

	split(head, &front, &back);
	sort(&front);
	sort(&back);
	//recursively merge the list
	*list = merge(front, back);
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
