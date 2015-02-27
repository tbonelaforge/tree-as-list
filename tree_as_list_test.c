
#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "permutation_iterator.h"
#include "permutation.h"

void test_inserting_permuted_elements(struct permutation * perm, int A[], int n) {
    int i;
    int index;
    int a;
    Node t = NULL;
    Node insert_result = NULL;
    Node l = NULL;
    void * v = NULL;

    for (i = 0; i < n; i++) {
        index = perm->_elements[i];
        a = A[index];
        v = (void *)(long int) a;
        insert_result = insert(t, v, &compare_as_ints);
        if (!t) {
            t = insert_result;
        }
    }
    printf("Converting:<br />\n");
    print_tree_html(t, &int_printer);
    printf("<br />\n");
    printf("to a list gives:<br />\n");
    l = convert_to_list(t);
    print_list(l, &int_printer);
    printf("<br /><br />\n");
}

void test_insert_S_N(int n) {
    int * A = NULL;
    int i;
    struct permutation_iterator * perm_it = NULL;

    // Initialize an array of numbers for the nodes.
    A = malloc(n * sizeof(int));
    if (!A) {
        printf("Ran out of memory!\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        A[i] = i;
    }

    // Prepare to permute the numbers.
    perm_it = new_permutation_iterator(n);
    if (!perm_it) {
        printf("Ran out of memory!\n");
    }

    // Test inserting all permutations of these numbers,
    // Creating a tree,
    // and listing out the tree.
    do {
        test_inserting_permuted_elements(perm_it->_permutation, A, n);
    } while (iterate_permutation(perm_it));
}

int main() {
    test_insert_S_N(2);
    test_insert_S_N(3);
    test_insert_S_N(4);
    test_insert_S_N(5);
}
