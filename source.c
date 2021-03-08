#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "list.h"


//read stdin to get the binary of a valid UTF-8 file
//count occurence of each character (even invisible ones)
//write a list to stdout with each char in descending order of count
int main() {
  setlocale(LC_ALL, "en_US.UTF-8");

  //my list of all unicode characters (stored as lists) and their count
  Node* list = (Node *) malloc(sizeof(Node));
  wint_t c;

  //loop thru stdin for unicode chars
  while((c = fgetwc(stdin)) != WEOF) {
    //add the completed character to the unicode list
      if (get(list, c) == NULL)
        list = push(list, c);
      //increment the count
      get(list, c)->count += 1;
  }

  //sort the completed list in descending order of occurrence
  list = sort(list);

  //print out the sorted list (to stdout)
  print(list);
  return 0;
}
