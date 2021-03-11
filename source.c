#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int countBytes(char* c);

//Garrett Alexander - Check COLLABORATORS for contributions and resources

/* Read stdin for a valid UTF-8 Unicode file. Then write a list
** to stdout with each char and how often it appears in descending order
*/
int main() {
  Node* list = NULL;
  char* c;

  //loop thru stdin for chars
  //fread() returns the length of what was written, it will differ from size(char) only at EOF or on error
  while(fread(c, sizeof(char), 1, stdin) == sizeof(char)) {
    //return c to stdin so it can be read to fullChar buffer after we know the full length
    ungetc(*c, stdin);

    //count how long the next unicode character is going to be
    int byteCount = countBytes(c);

    //read out the full unicode character
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = (char *) malloc(byteCount * sizeof(char));
    fread(node->data, sizeof(char), byteCount, stdin);
    
    if (get(list, node->data) == NULL)
      list = push(list, node);
    get(list, node->data)->count += 1;
  }

  //sort the completed list in descending order of occurrence
  sort(list);

  //print out the sorted list (to stdout)
  print(list);
  return 0;
}


//counts the number of bytes in a single unicode char from the first byte
int countBytes(char* c) {
  int byteCount = 0;
  while((*c & 0x80) == 0x80) {  //while the MSB is 1
      byteCount++;
      *c <<= 1;
  }
  return byteCount? byteCount: 1; //never read 0 bytes
}
