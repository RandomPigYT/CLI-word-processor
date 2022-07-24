#include "../include/wordP.h"

size_t fileSize;
size_t numLines;
size_t numChars;

bool isNewFile;


int currentFileFd;
char* currentFile;
size_t allocatedSize;
char* fileName;

int mode;

int charNum;
int lineNum;


struct stat sb;
