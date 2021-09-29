//
// Created by Hans Wan on 2021/9/29.
//

#include "stack/hds_stack.h"

void private_hds_stack_destroy_node(hds_stack_node_t *node)
{
    if (!node) {
        return;
    }
    if (node->next != NULL) {
        private_hds_stack_destroy_node(node->next);
    }
    free(node->data);
    free(node);
}

int hds_stack_init(hds_stack_t *self, size_t size)
{
    private_hds_stack_destroy_node(self->base);
    self->height = 0;
    self->base = NULL;
    self->top = NULL;
    self->nsize = size;
    return 0;
}