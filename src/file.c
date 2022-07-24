#define _GNU_SOURCE 1
#include "../include/wordP.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

void createFile(){
  
  currentFile = malloc(INITIAL_BUFF_SIZE);
  memset(currentFile, 0, INITIAL_BUFF_SIZE);
}


int openFile(const char* file){

  fileName = malloc(strlen(file));
  strcpy(fileName, file);

  currentFileFd = open(file, O_RDWR, S_IRUSR | S_IWUSR);
  
  if(fstat(currentFileFd, &sb) == -1){

    if(!S_ISREG(sb.st_mode) && !access(file, F_OK)){
      endwin();
      //fprintf(stderr, "Cannot open a directory\n");
      perror("Cannot open a directory");
      exit(EXIT_FAILURE);

    }
    
    
    return 1;

    
  }
  
  currentFile = malloc(sb.st_size);
  read(currentFileFd, currentFile, sb.st_size);
  
  
 
  
  return 0;
}
