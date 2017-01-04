cc = gcc
std = c11

name = wozdit
buffers = libbuffer.so

dyn_lib = ./lib/
tests = ./tests/
src = ./src/
headers = $(src)head/

build: buffer
	$(cc) -o $(name) -std=$(std) -L$(dyn_lib) -I$(headers) -lbuffer $(src)main.c
	
buffer : linked.o cursor.o
	mkdir -p ./$(dyn_lib)
	$(cc) -shared -fPIC -o $(dyn_lib)$(buffers) -L$(dyn_lib) -I$(headers) $(src)buffer.c linked.o cursor.o
	@rm -f *.o

cursor.o : linked.o
	$(cc) -c -I$(headers) $(src)cursor.c

linked.o :
	$(cc) -c -I$(headers) $(src)linked.c

test: buffer.so
	$(cc) -o $(linked)_test -std=$(std) -L$(dyn_lib) -I$(headers) -l$(linked)  $(tests)$(linked)_test.c
	$(cc) -o $(buffer)_test -std=$(std) -L$(dyn_lib) -I$(headers) -l$(buffer) $(tests)$(buffer)_test.c
	./$(linked)_test
	./$(buffer)_test

clean :
	@rm -f $(name)
	@rm -f *.o
	@rm -f linked_test
	@rm -f buffer_test
	@rm -f $(dyn_lib)*.so
