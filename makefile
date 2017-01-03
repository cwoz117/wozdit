cc = gcc
std = c11

name = wozdit
buffers = libbuffer.so
linked_list = liblinked.so
linked_test = linked_list

linked = linked
buffer = buffer
dependencies = -l$(buffer) -lncurses

dyn_lib = ./lib/
src = ./src/
tests = ./tests/
headers = $(src)head/

build: buffer.so
	$(cc) -o $(name) -std=$(std) -L$(dyn_lib) -I$(headers) $(dependencies) $(src)main.c
	
buffer.so : linked.so
	$(cc) -shared -fPIC -o $(dyn_lib)$(buffers) -L$(dyn_lib) -I$(headers) -l$(linked) $(src)buffer.c

linked.so :
	mkdir -p ./$(dyn_lib)
	$(cc) -shared -fPIC -o $(dyn_lib)$(linked_list) -L$(dyn_lib) -I$(headers) $(src)linked.c

test: linked.so
	$(cc) -o $(linked_test) -std=$(std) -L$(dyn_lib) -I$(headers) -l$(linked)  $(tests)linked_test.c
	./$(linked_test)

clean :
	@rm -f $(name)
	@rm -f $(linked_test)
	@rm -f $(dyn_lib)*.so
