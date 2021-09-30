//
// HDATASTRUCT - Hans' Data Structure Library
// Part II: Queue
//
// Header for queue
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#ifndef HDATASTRUCT_HDS_QUEUE_H
#define HDATASTRUCT_HDS_QUEUE_H

#include <stdlib.h>

/** QUEUE NODE TYPE */
typedef struct hds_queue_node_s {
    void *data;
#ifdef HDS_QUEUE_USE_DOUBLY_LINKED_LIST
    struct hds_queue_node_s *prev;
#endif
    struct hds_queue_node_s *next;
} hds_queue_node_t;

/** QUEUE TYPE */
typedef struct hds_queue_s {
    hds_queue_node_t *head;
    hds_queue_node_t *tail;
    int length;
    size_t nsize;
} hds_queue_t;

#endif //HDATASTRUCT_HDS_QUEUE_H
