/*
 * mygetch.hpp
 *
 *  Created on: Dec 5, 2010
 *      Author: Nikola Chonkov
 */
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#ifndef MYGETCH_HPP_
#define MYGETCH_HPP_

// Author: kermi3 @ http://cboard.cprogramming.com/faq-board/27714-faq-there-getch-conio-equivalent-linux-unix.html
// Emulates the functionality of getch() in the Windows implementation of conio.h - reads user input without the need
// to press enter
int mygetch();

#endif /* MYGETCH_HPP_ */
