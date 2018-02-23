#include "algo.h"

typedef struct list_node_t
{
    struct list_node_t *Next;
    i64 Value;
} list_node;

typedef struct
{
    list_node *Top;
    u32 CurrentSize;
    u32 MaxSize;
} linked_stack;

internal void
LinkedStackInitialize(linked_stack *Stack, u32 MaxSize)
{
    Stack->CurrentSize = 0;
    Stack->MaxSize = MaxSize;
    Stack->Top = 0;
}

internal u32
LinkedStackPush(linked_stack *Stack, i64 NewElement)
{
    i32 Result = 0;
    u32 CurrentSize = Stack->CurrentSize;
    if(CurrentSize < Stack->MaxSize)
    {
        Result = 1;
        list_node *NewTop = (list_node *)malloc(sizeof(list_node));
        NewTop->Value = NewElement;
        NewTop->Next = Stack->Top;
        Stack->Top = NewTop;
        Stack->CurrentSize = CurrentSize + 1;
    }
    return(Result);
}

internal i64
LinkedStackPop(linked_stack *Stack)
{
    // Maximum positive value indicates default (error) return value.
    i64 Result = (i64)(~(0)) >> 1;
    u32 CurrentSize = Stack->CurrentSize;
    if(CurrentSize > 0)
    {
        Result = Stack->Top->Value;
        list_node *ToDelete = Stack->Top;
        Stack->Top = Stack->Top->Next;
        free(ToDelete);
        Stack->CurrentSize = CurrentSize - 1;
    }
    return(Result);
}

internal void
LinkedStackFree(linked_stack *Stack)
{
	u32 Limit = Stack->CurrentSize;
	while(Stack->Top && Limit)
	{
		list_node *ToDelete = Stack->Top;	
		Stack->Top = Stack->Top->Next;
		free(ToDelete);
		--Limit;
	}
	Stack->CurrentSize = 0;
}

internal b32
LinkedStackIsFull(linked_stack *Stack)
{
    return Stack->CurrentSize == Stack->MaxSize;
}

internal b32
LinkedStackIsEmpty(linked_stack *Stack)
{
    return !(Stack->CurrentSize);
}
