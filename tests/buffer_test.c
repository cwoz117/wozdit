
#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include "linked.h"

BUFFER * setup(char * filename){
	BUFFER * buf = NULL;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL){
		printf("%s could not be opened\n", filename);
		exit(EXIT_FAILURE);
	}
	buf = build_buffer(fp);
	fclose(fp);

	return buf;
}

int main(){
	printf("Loading in a new buffer\n");
	BUFFER * buf = setup("./tests/test.txt");

	printf("Testing the cursor\n");
	print_list(buf);
	//printf(get_cursor_value(buf));

	printf("Freeing the buffer space\n");
	free_buffer(&buf);
}
