//
// HDATASTRUCT - Hans' Data Structure Library
// Part II: Queue
//
// Initialize
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_queue.h"

/**
 * Initialize a queue.
 * @param self The queue.
 * @param size The size of elements in the queue.
 * @return Always 0.
 */
int hds_queue_init(hds_queue_t *self, size_t size)
{
    self->length = 0;
    self->head = NULL;
    self->tail = NULL;
    self->nsize = size;
    return 0;
}