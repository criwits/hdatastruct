//
// HDATASTRUCT - Hans' Data Structure Library
// Part II: Queue
//
// Basic operations
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_queue.h"
#include <stdlib.h>

/**
 * Return the length of a queue.
 * @param self The queue.
 * @return
 */
int hds_queue_get_length(hds_queue_t *self)
{
    return self->length;
}

/**
 * Return the element size of a queue.
 * @param self The queue.
 * @return
 */
size_t hds_queue_get_size(hds_queue_t *self)
{
    return self->nsize;
}

/**
 * Return whether a queue is empty or not.
 * @param self The queue.
 * @return
 */
_Bool hds_queue_is_empty(hds_queue_t *self)
{
    return (hds_queue_get_length(self) == 0) ? 1 : 0;
}