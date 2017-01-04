cc = gcc
std = c11

name = wozdit
buffers = libbuffer.so
linked_list = liblinked.so

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

test: buffer.so
	$(cc) -o $(linked)_test -std=$(std) -L$(dyn_lib) -I$(headers) -l$(linked)  $(tests)$(linked)_test.c
	$(cc) -o $(buffer)_test -std=$(std) -L$(dyn_lib) -I$(headers) -l$(buffer) $(tests)$(buffer)_test.c
	./$(linked)_test
	./$(buffer)_test

clean :
	@rm -f $(name)
	@rm -f $(linked)_test
	@rm -f $(buffer)_test
	@rm -f $(dyn_lib)*.so
