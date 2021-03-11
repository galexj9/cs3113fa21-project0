#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"

//Garrett Alexander - Check COLLABORATORS for contributions and resources

/* Read stdin for a valid UTF-8 Unicode file. Then write a list
** to stdout with each char and how often it appears in descending order
*/
int main() {
  Node* list = NULL;
  char c;

  //loop thru stdin for chars
  while((c = (char) getc(stdin)) != EOF) {
    //return c to stdin so it can be read to fullChar buffer after we know the full length
    ungetc(c, stdin);

    //count how long the next unicode character is going to be
    int cBits = (int) c;
    int byteCount = 1;
    if((cBits << 1) & 0x80 != 0)
      while(cBits & 0x80 == 1) {
        byteCount++;
        cBits = cBits << 1;
      }
    printf("%d\n", byteCount);

    //read out the full unicode character
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = (char *) malloc(byteCount * sizeof(char));
    node->dataLen = fread(node->data, sizeof(char), byteCount, stdin); //write byteCount # bits to fullChar

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
