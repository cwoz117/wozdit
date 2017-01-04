#ifndef BUFFER_H
#define BUFFER_H

#include "linked.h"
#include "cursor.h"

typedef struct _buffer{
	CURSOR * cursor;
	NODE * file;
}BUFFER;

BUFFER * build_buffer(FILE *fp);
void free_buffer(BUFFER **buf);
#endif
