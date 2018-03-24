typedef double_list_node llbst_node;

typedef struct
{
  llbst_node *Root;
  i32 NodeCount;
} llbst;

internal void
LLBST_Destroy(llbst_node *Branch)
{
  llbst_node *CurrentNode = Branch;
  if(CurrentNode)
  {
    if(!CurrentNode->Prev && !CurrentNode->Next)
    {
      free(CurrentNode);
    }else if(!CurrentNode->Prev)
    {
      LLBST_Destroy(CurrentNode->Next);
      free(CurrentNode->Next);
    }else if(!CurrentNode->Next)
    {
      LLBST_Destroy(CurrentNode->Prev);
      free(CurrentNode->Prev);
    }else // Has both children.
    {
      LLBST_Destroy(CurrentNode->Next);
      LLBST_Destroy(CurrentNode->Prev);
      free(CurrentNode->Next);
      free(CurrentNode->Prev);
    }
  }
}

internal void
LLBST_AddElement(llbst *Tree, i64 Element)
{
  llbst_node *NewNode = calloc(1, sizeof(llbst_node));
  ++Tree->NodeCount;
  NewNode->Data = Element;
  if(Tree->Root)
  {
    llbst_node *CurrentNode = Tree->Root;
    while(CurrentNode)
    {
      if(CurrentNode->Data > Element)
      {
        if(CurrentNode->Prev)
        {
          CurrentNode = CurrentNode->Prev;
        }else
        {
          CurrentNode->Prev = NewNode;
          break;
        }
      }else // Element should become right child.
      {
        if(CurrentNode->Next)
        {
          CurrentNode = CurrentNode->Next;
        }else
        {
          CurrentNode->Next = NewNode;
          break;
        }
      }
    }
  }else // Tree is empty.
  {
    Tree->Root = NewNode;
  }
}

typedef struct
{
  llbst_node *Parent;
  llbst_node *FirstOccurence;
  b32 ChildFromLeft;
} llbst_find_node_result;

internal llbst_find_node_result
LLBST_FindNode(llbst *Tree, i64 Element)
{
  llbst_find_node_result Result = {0};
  if(Tree->Root)
  {
    llbst_node *CurrentNode = Tree->Root;
    while(CurrentNode && CurrentNode->Data != Element)
    {
      if(CurrentNode->Data > Element)
      {
        CurrentNode = CurrentNode->Prev;
      }else
      {
        CurrentNode = CurrentNode->Next;
      }
    }
    if(!CurrentNode)
    {
      return(Result);
    }
    Result.FirstOccurence = CurrentNode;
    CurrentNode = Tree->Root;
    if(Result.FirstOccurence != Tree->Root)
    {
      while(1)
      {
        if(CurrentNode->Prev == Result.FirstOccurence)
        {
          Result.Parent = CurrentNode;
          Result.ChildFromLeft = 1;
          break;
        }else if(CurrentNode->Next == Result.FirstOccurence)
        {
          Result.Parent = CurrentNode;
          Result.ChildFromLeft = 0;
          break;
        }
        if(CurrentNode->Data > Element)
        {
          CurrentNode = CurrentNode->Prev;
        }else
        {
          CurrentNode = CurrentNode->Next;
        }
      }
    }
  }
  return(Result);
}

internal i32
LLBST_RemoveElement(llbst *Tree, i64 Element)
{
  i32 Result = 0;
  llbst_find_node_result Data = LLBST_FindNode(Tree, Element);
  if(Data.FirstOccurence)
  {
    Result = 1;
    llbst_node *CurrentNode = Data.FirstOccurence;
    llbst_node *NodeToSet;
    llbst_node *PrevNode = 0;
    if(!CurrentNode->Prev && !CurrentNode->Next)
    {
      NodeToSet = 0;
    }else if(!CurrentNode->Prev)
    {
      NodeToSet = CurrentNode->Next;
    }else if(!CurrentNode->Next)
    {
      NodeToSet = CurrentNode->Prev;
    }else // Has both children.
    {
      NodeToSet = CurrentNode->Next;
      while(NodeToSet->Prev)
      {
        PrevNode = NodeToSet;
        NodeToSet = NodeToSet->Prev;
      }
      NodeToSet->Prev = CurrentNode->Prev;
      if(PrevNode)
      {
        PrevNode->Prev = 0;
      }
    }
    if(Data.Parent)
    {
      if(Data.ChildFromLeft)
      {
        Data.Parent->Prev = NodeToSet;
      }else
      {
        Data.Parent->Next = NodeToSet;
      }
      free(CurrentNode);
      --Tree->NodeCount;
    }else // Node is root.
    {
      Tree->Root = NodeToSet;
      free(NodeToSet);
      --Tree->NodeCount;
    }
  }
  return(Result);
}

internal void
LLBST_PrintPreOrder(llbst_node *Branch) //r<>
{
  if(Branch)
  {
    printf("|%lli|\n", Branch->Data);
    LLBST_PrintPreOrder(Branch->Prev);
    LLBST_PrintPreOrder(Branch->Next);
  }
}

internal void
LLBST_PrintInOrder(llbst_node *Branch) //<r>
{
  if(Branch)
  {
    LLBST_PrintInOrder(Branch->Prev);
    printf("|%lli|\n", Branch->Data);
    LLBST_PrintInOrder(Branch->Next);
  }
}

internal void
LLBST_PrintPostOrder(llbst_node *Branch) //<>r
{
  if(Branch)
  {
    LLBST_PrintPostOrder(Branch->Prev);
    LLBST_PrintPostOrder(Branch->Next);
    printf("|%lli|\n", Branch->Data);
  }
}

internal void
LLBST_PushInOrder(llbst_node *Branch, stack_t *Stack)
{
  if(Branch)
  {
    LLBST_PushInOrder(Branch->Prev, Stack);
    StackPush(Stack, Branch->Data);
    LLBST_PushInOrder(Branch->Next, Stack);
  }
}

internal void
LLBST_PrintDescending(llbst_node *Branch)
{
  void *Memory = calloc(1024,sizeof(i64));
  stack_t Stack = {0};
  StackInitialize(&Stack, 1024, Memory);
  LLBST_PushInOrder(Branch, &Stack);
  i32 ElementIndex = 0;
  for(;ElementIndex < Stack.CurrentSize;
      ++ElementIndex)
  {
    printf("|%lli|\n", StackPop(&Stack));
  }
  free(Memory);
}
