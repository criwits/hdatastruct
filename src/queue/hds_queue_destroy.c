//
// HDATASTRUCT - Hans' Data Structure Library
// Part II: Queue
//
// Destroy
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_queue.h"

void private_hds_queue_destroy_node(hds_queue_node_t *node)
{
    if (!node) {
        return;
    }
    if (node->next != NULL) {
        private_hds_queue_destroy_node(node->next);
    }
    free(node->data);
    free(node);
}

/**
 * Destroy a queue, then re-initialize it.
 * @param self The queue.
 * @return Always 0.
 */
int hds_queue_destroy(hds_queue_t *self)
{
    private_hds_queue_destroy_node(self->head);
    hds_queue_init(self, hds_queue_get_size(self));
    return 0;
}