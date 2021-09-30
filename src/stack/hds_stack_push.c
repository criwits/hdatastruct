//
// HDATASTRUCT - Hans' Data Structure Library
// Part I: Stack
//
// Push
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_stack.h"

/**
 * Push an element on top of a stack.
 * @param self The stack.
 * @param data A pointer to the element need to be pushed.
 * @param assign The function used to assign `data` into our stack. Usually
 * `memcpy` is used.
 * @return Always 0.
 */
int hds_stack_push(hds_stack_t *self, const void *data, void (*assign)(void *,
        const void *, size_t))
{
    if (hds_stack_is_empty(self)) {
        // Case 1: The stack is empty, so it's necessary to allocate new space
        // and set `base` as well as `top`.
        self->base = (hds_stack_node_t *)malloc(sizeof(hds_stack_node_t));
        self->base->data = malloc(hds_stack_get_size(self));
        self->top = self->base;
        self->base->next = NULL;
#ifdef HDS_STACK_USE_DOUBLY_LINKED_LIST
        self->base->prev = NULL;
#endif
        assign(self->base->data, data, hds_stack_get_size(self));
    } else {
        // Case 2: The stack has other element(s), modifying `next` and `prev`
        // pointers are necessary.
        self->top->next = (hds_stack_node_t *)malloc(sizeof(hds_stack_node_t));
        self->top->next->next = NULL;
#ifdef HDS_STACK_USE_DOUBLY_LINKED_LIST
        self->top->next->prev = self->top;
#endif
        self->top = self->top->next;
        self->top->data = malloc(hds_stack_get_size(self));
        assign(self->top->data, data, hds_stack_get_size(self));
    }
    (self->height)++;
    return 0;
}