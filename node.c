
#include <stdlib.h>
#include <stdio.h>

#include "node.h"

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


void print_list(Node head) {
    while (get_next(head)) {
        printf("%p, ", head);
        head = get_next(head);
    }
    printf("%p", head);
}
