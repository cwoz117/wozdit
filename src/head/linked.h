/*
	Interface for the Double-linked list
*/
#ifndef LINKED_H
#define LINKED_H

typedef struct _node {
	char character;
	struct _node * previous;
	struct _node * next;
}NODE;

void add_char(char c, NODE **index);	
void print_list(NODE *index);
void free_node(NODE **index);
#endif
