cc = gcc
std = c11
name = wozdit
dependencies = -llinked -lncurses
linked_list = liblinked.so

dyn_lib = lib/
src = src/
headers = $(src)head/

build: linked.so
	cc -o $(name) -std=$(std) -L$(dyn_lib) -I$(headers) $(dependencies) $(src)main.c
	
linked.so :
	cc -shared -fPIC -o $(dyn_lib)$(linked_list) $(src)linked.c

clean :
	rm $(name)
