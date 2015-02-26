
#include <stdio.h>

#include "node.h"


int main() {
    printf("About to construct a simple tree:\n");
    Node node1 = new_node();
    Node node2 = new_node();
    Node node3 = new_node();

    node2->left = node1;
    node2->right = node3;
    printf("The nodes are: \n %p, %p, %p\n", node1, node2, node3);
    printf("about to convert to a list\n");
    Node head = convert_to_list(node2);
    printf("After converting to a list, we have:\n");
    print_list(head);
    printf("\n");
}
