//
// HDATASTRUCT - Hans' Data Structure Library
// Part II: Queue
//
// Enqueue
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_queue.h"

/**
 * Enqueue an element into a queue.
 * @param self The queue.
 * @param data A pointer to the element need to be enqueued.
 * @param assign The function used to assign `data` into the queue. Usually
 * `memcpy` is used.
 * @return Always 0.
 */
int hds_queue_enqueue(hds_queue_t *self, const void *data, void (*assign)(void *,
        const void *, size_t))
{
    if (hds_queue_is_empty(self)) {
        self->head = (hds_queue_node_t *)malloc(sizeof(hds_queue_node_t));
        self->head->data = malloc(hds_queue_get_size(self));
        self->tail = self->head;
        self->head->next = NULL;
#ifdef HDS_QUEUE_USE_DOUBLY_LINKED_LIST
        self->head->prev = NULL;
#endif
        assign(self->head->data, data, hds_queue_get_size(self));
    } else {
        self->tail->next = (hds_queue_node_t *)malloc(sizeof(hds_queue_node_t));
        self->tail->next->next = NULL;
#ifdef HDS_QUEUE_USE_DOUBLY_LINKED_LIST
        self->tail->next->prev = self->tail;
#endif
        self->tail = self->tail->next;
        self->tail->data = malloc(hds_queue_get_size(self));
        assign(self->tail->data, data, hds_queue_get_size(self));
    }
    (self->length)++;
    return 0;
}