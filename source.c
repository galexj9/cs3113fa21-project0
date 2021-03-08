#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//read stdin to get the binary of a valid UTF-8 file
//count occurence of each character (even invisible ones)
//write a list to stdout with each char in descending order of count
int main() {
  //my list of all unicode characters (stored as lists) and their count
  Node* list = (Node *) malloc(sizeof(Node));
  wchar_t c;
  while((c = fgetc(stdin)) != EOF) {
    putchar(c);
  }


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

    //add the completed character to the unicode list
      if (get(list, &character) == NULL)
        push(list, &character);
      //increment the count
      get(list, &character)->count += 1;
  }

  //sort the completed list in descending order of occurrence
  list = sort(list);

  //print out the sorted list (to stdout)
  */
  //print(list);
  return 0;
}
