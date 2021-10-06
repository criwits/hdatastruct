//
// HDATASTRUCT - Hans' Data Structure Library
// Part I: Stack
//
// Header for stack
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#ifndef HDATASTRUCT_HDS_STACK_H
#define HDATASTRUCT_HDS_STACK_H

// `size_t` is needed
#include <stdlib.h>

/** STACK NODE TYPE */
typedef struct hds_stack_node_s {
    void *data;
#ifdef HDS_STACK_USE_DOUBLY_LINKED_LIST
    struct hds_stack_node_s *prev;
#endif
    struct hds_stack_node_s *next;
} hds_stack_node_t;

/** STACK TYPE */
typedef struct hds_stack_s {
    hds_stack_node_t *base, *top;
    size_t nsize;
    int height;
} hds_stack_t;

/** BASIC FUNCTIONS */
int hds_stack_get_height(hds_stack_t *self);
_Bool hds_stack_is_empty(hds_stack_t *self);
size_t hds_stack_get_size(hds_stack_t *self);

/** STACK OPERATIONS */
int hds_stack_init(hds_stack_t *self, size_t size);
int hds_stack_destroy(hds_stack_t *self);
int hds_stack_push(hds_stack_t *self, const void *data, void (*assign)(void *,
        const void *, size_t));
int hds_stack_pop(hds_stack_t *self, void *dest, void (*assign)(void *,
        const void *, size_t));

#endif //HDATASTRUCT_HDS_STACK_H
