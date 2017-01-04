cc = gcc
std = c11

name = wozdit
buffers = libbuffer.so

dyn_lib = ./lib/
tests = ./tests/
src = ./src/
headers = $(src)head/

build: buffer
	$(cc) -o $(name) -std=$(std) -L$(dyn_lib) -I$(headers) -lbuffer -lncurses $(src)main.c
	
test: buffer
	$(cc) -o buffer_test -std=$(std) -L$(dyn_lib) -I$(headers) -lbuffer $(tests)buffer_test.c
	./buffer_test
	@rm -f buffer_test

buffer : linked.o cursor.o
	mkdir -p ./$(dyn_lib)
	$(cc) -shared -fPIC -o $(dyn_lib)$(buffers) -L$(dyn_lib) -I$(headers) $(src)buffer.c linked.o cursor.o
	@rm -f *.o

cursor.o : linked.o
	$(cc) -c -I$(headers) $(src)cursor.c

linked.o :
	$(cc) -c -I$(headers) $(src)linked.c

clean :
	@rm -f $(name)
	@rm -f *.o
	@rm -f $(dyn_lib)*.so
