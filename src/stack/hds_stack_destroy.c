//
// HDATASTRUCT - Hans' Data Structure Library
// Part I: Stack
//
// Destroy
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_stack.h"

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

/**
 * Destroy a stack, then re-initialize it.
 * @param self The stack.
 * @return Always 0.
 */
int hds_stack_destroy(hds_stack_t *self)
{
    private_hds_stack_destroy_node(self->base);
    hds_stack_init(self, hds_stack_get_size(self));
    return 0;
}