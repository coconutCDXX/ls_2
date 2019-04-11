#include <ncurses.h>
// #include <curses.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handle_winch(int sig);

// SIGWINCH is called when the window is resized.
void handle_winch(int sig)
{
  signal(SIGWINCH, SIG_IGN);

  // Reinitialize the window to update data structures.
  endwin();
  initscr();
  refresh();
  clear();

  char tmp[128];
  sprintf(tmp, "%dx%d", COLS, LINES);
  // Approximate the center
  int x = COLS / 2 - strlen(tmp) / 2;
  int y = LINES / 2 - 1;

  mvaddstr(y, x, tmp);
  refresh();

  signal(SIGWINCH, handle_winch);
}

int main(int argc, char *argv[]){
  initscr();
  // COLS/LINES are now set

  signal(SIGWINCH, handle_winch);

  while(getch() != 27){
    /* Nada */
  }

  endwin();

  return(0);
}