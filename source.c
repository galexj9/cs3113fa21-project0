#include <stdio.h>   //fread()
#include <stdlib.h>  //malloc()
#include "list.h"

int countBytes(char* c);
void printOut(Node* list);

//Garrett Alexander

/* Read stdin for a valid UTF-8 Unicode file. Then write a list
** to stdout with each char and how often it appears in descending order
*/
int main() {
  Node* list = NULL;
  char* c;

  //loop thru stdin for chars
  while (fread(c, sizeof(char), 1, stdin) == sizeof(char)) {
    //return c to stdin so it can be read to fullChar buffer
    ungetc(*c, stdin);

    //count how long the next unicode character is going to be
    int byteCount = countBytes(c);

    //read out the full unicode character
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = (char *) malloc(byteCount * sizeof(char));
    node->dataLen = (int) fread(node->data, sizeof(char), byteCount, stdin);

		//printf("%s\n", node->data);

    if (get(list, node->data, node->dataLen) == NULL)
      list = push(list, node);
    get(list, node->data, node->dataLen)->count += 1;
  }

  //sorts in descending order by count
  list = sort(list);
  printOut(list);
  return 0;
}

void printOut(Node* list) {
	while(list) {
		(*list->data == '\n')?
			printf("\\n->%d\n", list->count) :
			printf("%s->%d\n", list->data, list->count);
		list = list->next;
	}
}


//counts the number of bytes in a single unicode char from the first byte
int countBytes(char* c) {
	if (*c == '\n') return 1;
  int byteCount = 0;
  while((*c & 0x80) == 0x80) {  //while the MSB is 1
      byteCount++;
      *c <<= 1;
  }
  return byteCount? byteCount: 1; //never read 0 bytes
}
