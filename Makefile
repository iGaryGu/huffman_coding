CC = g++
SHELL_HACK := $(shell mkdir -p BUILD)
OBJS = BUILD/main.o \
	   BUILD/priority_queue.o \
	   BUILD/file.o

all: huffman
inc = -I inc/
build_dir = BUILD
source_header := $(wildcard inc/*.h)

build_files = BUILD/%.o

BUILD/main.o: src/main.cpp $(source_header)
	$(CC) -c -o $@ src/main.cpp $(inc)
BUILD/priority_queue.o: src/priority_queue.cpp $(source_header)
	$(CC) -c -o $@ src/priority_queue.cpp $(inc)
BUILD/file.o: src/file.cpp $(source_header)
	$(CC) -c -o $@ src/file.cpp $(inc)

huffman: $(OBJS)
	$(CC) -o huffman $^

.PHONY: all clean

clean:
	rm -rf BUILD
