//
// HDATASTRUCT - Hans' Data Structure Library
// Part I: Stack
//
// Initialize
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_stack.h"

/**
 * Initialize a stack.
 * @param self The stack.
 * @param size The size of elements in the stack.
 * @return Always 0.
 */
int hds_stack_init(hds_stack_t *self, size_t size)
{
    self->height = 0;
    self->base = NULL;
    self->top = NULL;
    self->nsize = size;
    return 0;
}
