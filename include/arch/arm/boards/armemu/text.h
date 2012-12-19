#ifndef __TEXT_H
#define __TEXT_H

#include "display.h"

int initialize_text(void);
void draw_char(unsigned char c, int x, int y);
void set_text_color(unsigned int fg, unsigned int bg);

// libc routines
void __console_init(void);
void __puts(const char *str);
void putchar(char c);

#endif
