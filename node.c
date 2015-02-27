
#include <stdlib.h>
#include <stdio.h>

#include "node.h"

void int_printer(void * value) {
    long int v = (long int) value;

    printf("%ld", v);
}

// Constants used when navigating tree children
int LEFT = 0;
int RIGHT = 1;

Node new_node() {
    Node self = malloc(sizeof(struct node));

    if (!self) {
        return NULL;
    }
    self->value = self->left = self->right = NULL;
    return self;
}


Node convert_to_list(Node self) {
    Node left_list = NULL;
    Node right_list = NULL;
    Node list = NULL;

    if (!self) {
        return NULL;
    }
    left_list = convert_to_list(self->left);
    right_list = convert_to_list(self->right);
    self = convert_to_singleton_list(self);
    list = join_as_lists(left_list, self);
    list = join_as_lists(list, right_list);
    return list;
}

Node convert_to_singleton_list(Node self) {
    set_tail(self, self);
    set_tail(get_tail(self), self); // Set head.
    set_next(self, NULL);
    return self;
}

Node join_as_lists(Node a, Node b) {
    Node a_head;
    Node a_tail;
    Node b_head;
    Node b_tail;

    if (!a && !b) {
        return NULL;
    }
    if (!a) {
        return get_head(b);
    }
    if (!b) {
        return get_head(a);
    }
    a_head = get_head(a);
    a_tail = get_tail(a);
    b_head = get_head(b);
    b_tail = get_tail(b);
    set_next(a_tail, b_head);
    set_tail(a, b_tail);
    set_tail(b_tail, a);
    set_next(b_tail, NULL);
    return a_head;
}

Node get_tail(Node self) {
    return self->right;
}

Node set_tail(Node self, Node tail) {
    return self->right = tail;
}

Node get_next(Node self) {
    return self->left;
}

Node set_next(Node self, Node next) {
    return self->left = next;
}
Node get_head(Node self) {
    Node tail = get_tail(self);

    return get_tail(tail);
}


void print_list(Node head, ptr2valueprinter printer) {
    if (!head) {
        return;
    }
    while (get_next(head)) {
        (*printer)(head->value);
        printf(", ");
        head = get_next(head);
    }
    (*printer)(head->value);
}

void print_tree_html(Node self, ptr2valueprinter printer) {
    if (!self) {
        return;
    }
    printf("<table border=\"1\"><tr align=\"center\"><td colspan=\"2\">");
    (*printer)(self->value);
    printf("</td></tr>");
    printf("<tr><td valign=\"top\">");
    print_tree_html(self->left, printer);
    printf("</td><td valign=\"top\">");
    print_tree_html(self->right, printer);
    printf("</td></tr>");
    printf("</table>");
}

Node insert(Node self, void * value, ptr2comparator comp) {
    Node current = self;
    Node value_node = NULL;
    Node previous = NULL;
    int comparison;
    int side;

    value_node = new_node();
    if (!value_node) {
        return NULL;
    }
    value_node->value = value;
    while (current) {
        previous = current;
        comparison = (*comp)(value, current->value);
        if (comparison < 0) {
            side = LEFT;
            current = current->left;
        } else {
            side = RIGHT;
            current = current->right;
        }
    }
    if (previous) {
        if (side == LEFT) {
            previous->left = value_node;
        } else {
            previous->right = value_node;
        }
    }
    return value_node;
}
