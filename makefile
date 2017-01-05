cc = gcc
std = c11

name = wozdit
buffer_lib = libbuffer.so

dyn_lib = ./lib/
tests = ./tests/
src = ./src/

headers = $(src)head/
structures = $(src)structures/

build: buffer
	$(cc) -o $(name) -std=$(std) -L$(dyn_lib) -I$(headers) -lbuffer -lncurses $(src)main.c
	
test: buffer
	$(cc) -o buffer_test -std=$(std) -L$(dyn_lib) -I$(headers) -lbuffer $(tests)buffer_test.c
	./buffer_test
	@rm -f buffer_test

buffer : linked.o cursor.o
	mkdir -p ./$(dyn_lib)
	$(cc) -shared -fPIC -o $(dyn_lib)$(buffer_lib) -L$(dyn_lib) -I$(headers) $(structures)buffer.c linked.o cursor.o
	@rm -f *.o

cursor.o : linked.o
	$(cc) -c -I$(headers) $(structures)cursor.c

linked.o :
	$(cc) -c -I$(headers) $(structures)linked.c

clean :
	@rm -f $(name)
	@rm -f *.o
	@rm -f $(dyn_lib)*.so
