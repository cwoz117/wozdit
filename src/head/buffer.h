#ifndef BUFFER_H
#define BUFFER_H

typedef struct _buffer BUFFER;

BUFFER * build_buffer(FILE *fp);
void free_buffer(BUFFER **buf);
#endif
