#include "../include/wordP.h"
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>

void quit(){

}

void init(){
  
  signal(SIGSEGV, handleSigsegv);
  initscr();
  refresh();
  
  atexit(cleanUp);
}
