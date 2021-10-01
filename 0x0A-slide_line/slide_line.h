#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void shift_all_left(int *line, size_t size);
void shift_all_right(int *line, size_t size);
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#endif
