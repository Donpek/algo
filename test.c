#include "algo.h"
internal void
TestStack(void)
{
    printf("\tSTACK.C\n");
    void *Memory = malloc(8 * KILOBYTE);

    stack_t Stack = {0};
    StackInitialize(&Stack, 1000, Memory);
    printf("IsEmpty: %d\n", StackIsEmpty(&Stack));

    u32 ElementIndex;
    for(ElementIndex = 0;
        ElementIndex < Stack.MaxSize;
        ++ElementIndex)
    {
        StackPush(&Stack, RangeI64(-10000, 10000));
    }

    printf("IsFull: %d\n", StackIsFull(&Stack));

    printf("Popped values:\n");
    for(ElementIndex = 0;
        ElementIndex < Stack.MaxSize;
        ++ElementIndex)
    {
        printf("%lld\n", StackPop(&Stack));
    }
    free(Memory);
}

internal void
TestLinkedListStack(void)
{
    printf("\tLINKED_LIST_STACK.C\n");

    linked_stack Stack = {0};
    LinkedStackInitialize(&Stack, 1000);
    printf("IsEmpty: %d\n", LinkedStackIsEmpty(&Stack));

    u32 ElementIndex;
    for(ElementIndex = 0;
        ElementIndex < Stack.MaxSize;
        ++ElementIndex)
    {
        LinkedStackPush(&Stack, ElementIndex);
    }

    printf("IsFull: %d\n", LinkedStackIsFull(&Stack));

    printf("Popped values:\n");
    for(ElementIndex = 0;
        ElementIndex < Stack.MaxSize;
        ++ElementIndex)
    {
        printf("%lld\n", LinkedStackPop(&Stack));
    }
}
