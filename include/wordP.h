#ifndef WORD_PROCESSOR_H
#define WORD_PROCESSOR_H

#include <ncurses.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <bits/mman-linux.h>
#include <signal.h>

#define INITIAL_BUFF_SIZE 4096

enum {
  NORMAL,
  INSERT,
  REPLACE
};

extern size_t fileSize;
extern size_t allocatedSize;
extern size_t numLines;
extern size_t numChars;

extern bool isNewFile;

extern int currentFileFd;
extern char* currentFile;
extern char* fileName;

extern struct stat sb;

extern int mode;

extern int charNum;
extern int lineNum;

void init();
void quit();
int openFile(const char* file);
void createFile();
void handleSigsegv();
void cleanUp();

void input();
void changeMode();
void insertChar();
void replaceChar();
void delChar();

void update();


#endif //WORD_PROCESSOR_H
