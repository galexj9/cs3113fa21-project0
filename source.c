#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "list.h"

//Garrett Alexander - Check COLLABORATORS for contributions and resources

/* Read stdin for a valid UTF-8 Unicode file. Then write a list
** to stdout with each char and how often it appears in descending order
*/
int main() {
  setlocale(LC_ALL, "en_US.UTF-8");

  //my list of all unicode characters and their count
  Node* list = NULL;
  wint_t c;

  //loop thru stdin for unicode chars
  while((c = fgetwc(stdin)) != WEOF) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = c;
    node->count = 0;
      if (get(list, c) == NULL)
        list = push(list, node);
      //increment the count
      get(list, c)->count += 1;
  }

  //sort the completed list in descending order of occurrence
  sort(list);

  //print out the sorted list (to stdout)
  print(list);
  return 0;
}
