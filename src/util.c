#include "../include/wordP.h"

void handleSigsegv(){

  endwin();
  fprintf(stderr, "Segmentation fault\n");

  exit(EXIT_FAILURE);
}

void cleanUp(){
  
  endwin();
  close(currentFileFd);

  free(currentFile);
  free(fileName);
  
}
