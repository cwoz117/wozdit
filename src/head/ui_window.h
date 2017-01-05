#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <ncursus.h>

void init_ncursus();
void destroy_ncursus();
void destroy_window(WINDOW * view);
WINDOW * build_window();

#endif
