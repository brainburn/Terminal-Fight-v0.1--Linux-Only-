/*
 * mygetch.cpp
 *
 *  Created on: Dec 5, 2010
 *      Author: kermi3
 */

#include "mygetch.hpp"

// Author: kermi3 @ http://cboard.cprogramming.com/faq-board/27714-faq-there-getch-conio-equivalent-linux-unix.html
// Emulates the functionality of getch() in the Windows implementation of conio.h - reads user input without the need
// to press enter
int mygetch() {
  struct termios oldt,
                 newt;
  int            ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}


