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

  //loop thru stdin for unicode chars
  wint_t c;

  while((c = fgetwc(stdin)) != WEOF) {
    //add the completed character to the unicode list
      //if (get(list, *c) == NULL)
        //list = push(list, *c);
      //increment the count
      //get(list, c)->count += 1;
      //printf("%ls\n", c);
      printf("%lc\n", c);
  }

  //sort the completed list in descending order of occurrence
  //list = sort(list);

  //print out the sorted list (to stdout)
  //print(list);
  return 0;

  /*
  int c;
  //loop through stdin to construct the unicode count list
  while((c = getchar()) != EOF) {
    //create a new list to store a single unicode character
    Node* character = (Node *) malloc(sizeof(Node));
    int byteCount = 1; //minimum length 1
    int cbits = c << 1; //the first '1' is counted for already

    //count the length of the unicode char
    while(cbits & 0x80 == 1) { //while the first bit is 1
      cbits = cbits << 1;  //left shift 1
      byteCount++;
    }

    //build the character lsit
    while(byteCount > 0) {
      push(character, &c);
      c = getchar();
      byteCount--;
    }
  } */
}
