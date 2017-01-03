cc = gcc
std = c11
name = wozdit
linked_list = liblinked.so
buffers = libbuffers.so
dyn_lib = lib/
src = src/
headers = $(src)head/

build: buffer.so
	$(cc) -o $(name) -std=$(std) -L$(dyn_lib) -I$(headers) $(dependencies) $(src)main.c
	
buffer.so : linked.so
	$(cc) -shared -fPIC -o $(dyn_lib)$(buffers) -L$(dyn_lib) -I$(headers) -llinked $(src)buffer.c

linked.so :
	mkdir -p ./$(dyn_lib)
	$(cc) -shared -fPIC -o $(dyn_lib)$(linked_list) -L$(dyn_lib) -I$(headers) $(src)linked.c

clean :
	rm $(name)
	rm $(dyn_lib)*.so
