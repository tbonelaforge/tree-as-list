all: permutation_iterator tree_as_list_test.bin

tree_as_list_test.bin: tree_as_list_test.c node.h node.o
	gcc -I ./ -I ./permutation_iterator/ tree_as_list_test.c node.o permutation_iterator/permutation_iterator.o permutation_iterator/permutation.o -o tree_as_list_test.bin

node.o: node.c node.h
	gcc -I ./ -c node.c -o node.o

.PHONY: permutation_iterator

permutation_iterator:
	cd ./permutation_iterator; make
