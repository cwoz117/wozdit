/*
	Interface for the Double-linked list
*/
#ifndef LINKED_H
#define LINKED_H

typedef struct _node NODE;

void add_char(char c, NODE **index);	
void print_list(NODE *index);
void free_node(NODE **index);
NODE * setup_cursor(NODE **index);
#endif
