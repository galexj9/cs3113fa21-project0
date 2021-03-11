#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "list.h"

//Garrett Alexander - Check COLLABORATORS for contributions and resources

/* Read stdin for a valid UTF-8 Unicode file. Then write a list
** to stdout with each char and how often it appears in descending order
*/
int main() {
  //my list of all unicode characters and their count
  Node* list = NULL;
  char c;

  //loop thru stdin for chars
  while((c = (char) getc(stdin)) != EOF) {
    Node* node = (Node *) malloc(sizeof(Node));

    int cBits = (int) c;
    int byteCount = 1;
    if(cBits & 0x80 != 0)
      while((cBits << 1) & 0x80 == 1)
        btyteCount++;

    char* fullChar = (char *) malloc(byteCount * sizeof(char));
    ungetc(c, stdin); //return c to stdin to read on the next line
    node->dataLen = read(stdin, fullChar, byteCount); //write byteCount # bits to fullChar
    node->data = fullChar;

    if (get(list, fullChar) == NULL)
      list = push(list, node);
    //increment the count
    get(list, fullChar)->count += 1;
  }

  //sort the completed list in descending order of occurrence
  sort(list);

  //print out the sorted list (to stdout)
  print(list);
  return 0;
}
