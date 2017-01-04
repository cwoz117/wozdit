#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main(){
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
}
