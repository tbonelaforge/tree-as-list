all: tree_as_list_test.bin

tree_as_list_test.bin: tree_as_list_test.c node.h node.o
	gcc -I ./ tree_as_list_test.c node.o -o tree_as_list_test.bin

node.o: node.c node.h
	gcc -I ./ -c node.c -o node.o
