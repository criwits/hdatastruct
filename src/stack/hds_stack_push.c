//
// Created by Hans Wan on 2021/9/30.
//

#include "stack/hds_stack.h"
#include <string.h>

int hds_stack_push(hds_stack_t *self, const void *data, void (*assign)(void *,
        const void *))
{
    if (hds_stack_is_empty(self)) {
        self->base = (hds_stack_node_t *)malloc(sizeof(hds_stack_node_t));
        self->base->data = malloc(hds_stack_get_size(self));
        self->top = self->base;
        self->base->next = NULL;
        if (assign == NULL) {
            memcpy(self->base->data, data, hds_stack_get_size(self));
        } else {
            (*assign)(self->base->data, data);
        }
    } else {
        self->top->next = (hds_stack_node_t *)malloc(sizeof(hds_stack_node_t));
        self->top->next->next = NULL;
        self->top = self->top->next;
        self->top->data = malloc(hds_stack_get_size(self));
        if (assign == NULL) {
            memcpy(self->top->data, data, hds_stack_get_size(self));
        } else {
            (*assign)(self->top->data, data);
        }
    }
    (self->height)++;
    return 0;
}