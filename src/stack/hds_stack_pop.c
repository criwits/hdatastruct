//
// HDATASTRUCT - Hans' Data Structure Library
// Part I: Stack
//
// Pop
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//


#include "hds_stack.h"

#ifndef HDS_STACK_USE_DOUBLY_LINKED_LIST
hds_stack_node_t *private_hds_stack_get_next_node(hds_stack_node_t *node, int n)
{
    if (!n) {
        return node;
    } else {
        return private_hds_stack_get_next_node(node->next, n - 1);
    }
}
#endif

/**
 * Pop an element out of a stack.
 * @param self The stack.
 * @param dest A pointer to the place to store the element.
 * @param assgin The function used to assign the element to `dest`. Usually
 * `memcpy` is used.
 * @return 0 for ok, 1 if the stack is empty.
 */
int hds_stack_pop(hds_stack_t *self, void *dest, void (*assign)(void *,
        const void *, size_t))
{
    if (hds_stack_is_empty(self)) {
        return 1;
    } else {
        assign(dest, self->top->data, hds_stack_get_size(self));
        free(self->top->data);
        if (hds_stack_get_height(self) == 1) {
            free(self->top);
            self->base = NULL;
            self->top = NULL;
        } else {
#ifdef HDS_STACK_USE_DOUBLY_LINKED_LIST
            self->top = self->top->prev;
            free(self->top->next);
            self->top->next = NULL;
#else
            free(self->top);
            self->top = private_hds_stack_get_next_node(self->base,
                                                        hds_stack_get_height(self) - 2);
            self->top->next = NULL;
#endif
        }
    }
    (self->height)--;
    return 0;
}
