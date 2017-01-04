/*
	Buffer for a file
*/
#include <stdlib.h>
#include <stdio.h>
#include "linked.h"
#include "cursor.h"

typedef struct _buffer{
	CURSOR * cursor;
	NODE * file;
}BUFFER;

BUFFER * build_buffer(FILE *fp){
	BUFFER *buf = malloc(sizeof(BUFFER));
	if (buf == NULL){
		fclose(fp);
		perror("build_buffer\t could not create a buffer structure");
		exit(EXIT_FAILURE);
	}
	buf->file = NULL;
	char c;	
	while ((c = fgetc(fp)) != EOF){
		add_char(c, &(buf->file));	
	}
	buf->cursor = setup_cursor(&(buf->file)); 

	return buf;
}

void free_buffer(BUFFER **buf){
	free_node(&((*buf)->file));
	free(*buf);
	(*buf) = NULL;
}
