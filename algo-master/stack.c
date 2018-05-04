typedef struct
{
    i64 *Top;
    u32 CurrentSize;
    u32 MaxSize;
} stack_t;

internal i64
StackPop(stack_t *Stack)
{
    // Maximum positive value indicates default (error) return value.
    i64 Result = (i64)(~(0)) >> 1;
    if(Stack->CurrentSize > 0)
    {
        --Stack->Top;
        Result = *Stack->Top;
        --Stack->CurrentSize;
    }
    return(Result);
}

internal i32
StackPush(stack_t *Stack, i64 NewElement)
{
    i32 Result = 0;
    if(Stack->CurrentSize < Stack->MaxSize)
    {
        Result = 1;
        *Stack->Top = NewElement;
        ++Stack->Top;
        ++Stack->CurrentSize;
    }
    return(Result);
}

internal b32
StackIsFull(stack_t *Stack)
{
    return Stack->CurrentSize == Stack->MaxSize;
}

internal b32
StackIsEmpty(stack_t *Stack)
{
    return !(Stack->CurrentSize);
}

internal void
StackInitialize(stack_t *Stack, u32 MaxSize, void *Memory)
{
    Stack->CurrentSize = 0;
    Stack->MaxSize = MaxSize;
    Stack->Top = (i64 *)Memory;
}
