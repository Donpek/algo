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

internal void
TestArrayQueue(void)
{
	printf("\tARRAY-BASED QUEUE\n");
    void *Memory = malloc(8 * KILOBYTE);

    array_queue_t Queue = {0};
    QueueInitialize(&Queue, Memory, 1024);

    i32 ElementIndex = 0;
    for(;ElementIndex < Queue.MaxSize;
        ++ElementIndex)
    {
        QueueEnqueue(&Queue, ElementIndex);
    }

    printf("Dequeued values:\n");
    for(ElementIndex = 0;
        ElementIndex < Queue.MaxSize;
        ++ElementIndex)
    {
        printf("%lld\n", QueueDequeue(&Queue));
    }
    free(Memory);
}

internal void
TestLLBST(void)
{
  printf("\tLINKED-LIST BINARY SEARCH TREE\n");
  llbst Tree = {0};
  i32 ElementIndex = 0;
  for(;ElementIndex < 25;
      ++ElementIndex)
  {
    i64 Element = RangeI64(1,100);
    LLBST_AddElement(&Tree, Element);
    printf("ADDED %lli ", Element);
    printf("Added %lli.\n", LLBST_FindNode(&Tree, Element).FirstOccurence->Data);
  }
  printf("Preorder:\n");
  LLBST_PrintPreOrder(Tree.Root);
  printf("Inorder:\n");
  LLBST_PrintInOrder(Tree.Root);
  printf("Postorder:\n");
  LLBST_PrintPostOrder(Tree.Root);
  printf("Descending:\n");
  LLBST_PrintDescending(&Tree);
  ElementIndex = 0;
  for(;ElementIndex < 100;
      ++ElementIndex)
  {
    i64 Element = RangeI64(1,100);
    if(LLBST_RemoveElement(&Tree, Element))
    {
      printf("Removed %lli.\n", Element);
    }
  }
  printf("Preorder:\n");
  LLBST_PrintPreOrder(Tree.Root);
  printf("Inorder:\n");
  LLBST_PrintInOrder(Tree.Root);
  printf("Postorder:\n");
  LLBST_PrintPostOrder(Tree.Root);
  
  printf("Descending:\n");
  LLBST_PrintDescending(&Tree);
  
  LLBST_Destroy(Tree.Root);
}
