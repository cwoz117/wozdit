/*
	Linked list

	payload is a character.
*/

#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

typedef struct _node {
	char character;
	struct _node * previous;
	struct _node * next;
}NODE;

static NODE * insert_node(NODE *previous, char c, NODE *next){
	NODE *n = malloc(sizeof(NODE));
	if (n == NULL){
		perror("build_node:\t Could not malloc mem-space");
		return NULL;
	}
	n->character = c;
	n->previous = previous;
	n->next = next;
	return n;
}

void add_char(char c, NODE ** index){
	if (*index == NULL){ // new linked list
		*index = insert_node(NULL, c, NULL);
	} else if ((*index)->next == NULL) // last node
		(*index)->next = insert_node(*index, c, NULL);
	else // recursive step
		add_char(c, &((*index)->next));
}

void print_list(NODE *index){
	if (index != NULL) {
		printf("%c", index->character);
		print_list(index->next);
	}
}

void free_node(NODE ** index){
	if ((*index)->next == NULL) {
		free((*index));
		(*index) = NULL;
	}else {
		free_node(&((*index)->next));
		free((*index));
		(*index) = NULL;
	}
}
//TODO 	Should be in buffer.c but 
//		requires the NODE sizes for malloc
NODE * setup_cursor(NODE **index){
	NODE * cursor = malloc(sizeof(NODE));
	if (cursor == NULL)
		return NULL;
	cursor = *index;
	cursor->next = (*index)->next;
	cursor->previous = NULL;

	

}
