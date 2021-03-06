
#ifndef _NODE_H_
#define _NODE_H_

struct node {
    void * value;
    struct node * left;
    struct node * right;
};

typedef struct node * Node;

typedef void (*ptr2valueprinter)(void *);

typedef int (*ptr2comparator)(void *, void *);

Node new_node();
Node convert_to_list(Node);
Node convert_to_singleton_list(Node);
Node join_as_lists(Node, Node);
Node get_next(Node);
Node get_tail(Node);
Node get_head(Node);
Node set_next(Node, Node);
Node set_tail(Node, Node);
void print_list(Node, ptr2valueprinter);
void print_tree_html(Node, ptr2valueprinter);
Node insert(Node, void *, ptr2comparator);
void int_printer(void *);

#endif
