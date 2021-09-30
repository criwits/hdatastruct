//
// HDATASTRUCT - Hans' Data Structure Library
// Part I: Stack
//
// Basic operations
// (C) Hans Wan. Licensed under Mozilla Public License 2.0
//

#include "hds_stack.h"

/**
 * Return the height of a stack.
 * @param self
 * @return
 */
int hds_stack_get_height(hds_stack_t *self)
{
    return self->height;
}

/**
 * Return whether a stack is empty or not.
 * @param self
 * @return
 */
_Bool hds_stack_is_empty(hds_stack_t *self)
{
    return (hds_stack_get_height(self) == 0) ? 1 : 0;
}

/**
 * Return the element size of a stack.
 * @param self
 * @return
 */
size_t hds_stack_get_size(hds_stack_t *self)
{
    return self->nsize;
}