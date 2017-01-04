
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
/*================================================*/
	NODE * test_node = NULL;

	printf("Adding the string `car`\n");
	add_char('c', &test_node);
	add_char('a', &test_node);
	add_char('r', &test_node);
	
	printf("Printing a list\n");
	print_list(test_node);
	printf("\n");
	
	printf("Freeing a list\n");
	free_node(&test_node);
	if (test_node == NULL)
		printf("Successfully deleted the linked list\n");

/*================================================*/
	printf("Loading in a new buffer\n");
	BUFFER * buf = setup("./tests/test.txt");

	printf("Testing the cursor\n");
	print_list(buf->file);
	//printf(get_cursor_value(buf));

	printf("Freeing the buffer space\n");
	free_buffer(&buf);

/*================================================*/
}
