#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack/hds_stack.h"

int main()
{
    hds_stack_t my_stack;
    hds_stack_init(&my_stack, sizeof(int));
    int a = 12;
    hds_stack_push(&my_stack, &a, NULL);
    printf("Hello, World!\n");
    return 0;
}
