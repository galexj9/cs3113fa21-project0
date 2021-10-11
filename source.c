#include <stdio.h>   //fread()
#include <stdlib.h>  //malloc()
#include "list.h"    //a linked list of unichars

int countBytes(char* c);
void printOut(Node* list);

//Garrett Alexander

/* Read stdin for valid UTF-8 Unicode. Then write a list
** of all chars in descending order to stdout 				*/
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

		//push new chars to the list and inc count
    if (get(list, node->data, node->dataLen) == NULL)
      list = push(list, node);
    get(list, node->data, node->dataLen)->count += 1;
  }

  //sort list in descending order by count
  list = sort(list);
  printOut(list);
  return 0;
}

//prints a linked Node* list in the format 'char->count'
void printOut(Node* list) {
	while(list) {
		switch (*list->data) { 
			case '\n':
				printf("\\n");
				break;
			case '\t':
				printf("\\t");
				break;
			default:
				printf("%s", list->data);
		}
		printf("->%d\n", list->count);
		list = list->next;
	}
}


//counts the number of bytes in a single unicode char from the first byte
int countBytes(char* c) {
  int byteCount = 0;
  while((*c & 0x80) == 0x80) {  //while the MSB is 1
      byteCount++;
      *c <<= 1; //shift char 1 bit left
  }
  return byteCount? byteCount: 1; //never read 0 bytes
}
