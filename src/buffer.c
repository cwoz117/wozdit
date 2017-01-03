/*
	Buffer for a file
*/
#include <stdlib.h>
#include <stdio.h>
#include <linked.h>

struct _cursor{
	int row;
	int column;
};

typedef struct _buffer{
	struct _cursor cursor;
	NODE * character;
}BUFFER;

BUFFER * build_buffer(FILE *fp){
	BUFFER *buf = malloc(sizeof(BUFFER));
	if (buf == NULL){
		fclose(fp);
		perror("build_buffer\t could not create a buffer structure");
		exit(EXIT_FAILURE);
	}
	
	char c;	
	while ((c = fgetc(fp)) != EOF){
		add_char(c, buf->character);	
	}
	buf->cursor.row = 0;
	buf->cursor.column = 0;	
	
	return buf;
}

void free_buffer(BUFFER *buf){
	free_node(buf->character);
	free(buf);
}
