#include "algo.h"
#include "stack.c"
#include "linked_list_stack.c"
#include "test.c"

int main(void)
{
    srand(0);
    TestStack();
    TestLinkedListStack();

    return 0;
}
