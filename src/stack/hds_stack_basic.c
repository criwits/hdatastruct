//
// Created by Hans Wan on 2021/9/30.
//

#include "stack/hds_stack.h"

int hds_stack_get_height(hds_stack_t *self)
{
    return self->height;
}

_Bool hds_stack_is_empty(hds_stack_t *self)
{
    return (self->height == 0) ? 1 : 0;
}

size_t hds_stack_get_size(hds_stack_t *self)
{
    return self->nsize;
}