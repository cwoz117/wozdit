#ifndef CURSOR_H
#define CURSOR_H

#include "linked.h"

typedef struct _cursor{
	int row;
	int col;
	NODE *cursor;
}CURSOR;

CURSOR * setup_cursor(NODE **index);
void free_cursor(NODE **cursor);
void advance_cursor(NODE **cursor);
void retreat_cursor(NODE **cursor);

#endif
