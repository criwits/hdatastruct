#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hds_stack.h"

int main()
{
    hds_stack_t my_stack;
    hds_stack_init(&my_stack, sizeof(int));
    int a = 12, b = 23, c, d;
    hds_stack_push(&my_stack, &a, memcpy);
    hds_stack_push(&my_stack, &b, memcpy);
    printf("%d\n", hds_stack_get_height(&my_stack));

    hds_stack_pop(&my_stack, &c, memcpy);
    hds_stack_pop(&my_stack, &d, memcpy);

    printf("%d %d\n", c, d);
    printf("Hello, World!\n");
    return 0;
}
