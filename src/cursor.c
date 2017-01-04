#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "cursor.h"

CURSOR * setup_cursor(NODE **index){
	CURSOR * cursor = malloc(sizeof(CURSOR));
	if (cursor == NULL)
		return NULL;
	cursor->cursor = *index;
	cursor->cursor->next = (*index)->next;
	cursor->cursor->previous = NULL;
	cursor->row = 0;
	cursor->col = 0;
	return cursor;	
}

void free_cursor(NODE **cursor){
	free((*cursor));
}

void advance_cursor(NODE **cursor){
	if ((*cursor) != NULL){	
		if ((*cursor)->next != NULL){
			(*cursor)->next->previous = (*cursor);
			(*cursor) = (*cursor)->next;
		}
	}
}

void retreat_cursor(NODE **cursor){
	if ((*cursor) != NULL){	
		if ((*cursor)->previous != NULL){
			(*cursor)->previous->next = (*cursor);
			(*cursor) = (*cursor)->previous;
		}
	}
}
