#define _GNU_SOURCE 1
#include "../include/wordP.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
  
  if(argc < 2 || argc > 2){
    fprintf(stderr, "enter a valid argument\n");
    exit(EXIT_FAILURE);
  }
  init();

  if(openFile(argv[1]) == 1){
    isNewFile = true;
    createFile();
    printw("[new]\t");
  }
  
  

  printw("%s\n\n%s\n", fileName, currentFile);
  refresh();

  while(1){
    
    if(getch() == 27) break;
  }

  
}
