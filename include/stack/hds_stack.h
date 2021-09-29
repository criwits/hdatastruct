//
// Hans' Data Structure Library
// Header for stack
//

#ifndef HDATASTRUCT_HDS_STACK_H
#define HDATASTRUCT_HDS_STACK_H

// `size_t` is needed
#include <stdlib.h>

/** Stack node type */
typedef struct hds_stack_node_s {
    void *data;
    struct hds_stack_node_s *next;
} hds_stack_node_t;


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
int hds_stack_push(hds_stack_t *self, const void *data, void (*assign)(void *,
        const void *));

#endif //HDATASTRUCT_HDS_STACK_H
