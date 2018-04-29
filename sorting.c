#define SORT_ASCENDING 0
#define SORT_DESCENDING 1

static void
InsertionSort(i64 *Array, i64 Size, i32 Order)
{
  int InsertionIndex = 1, CandidateIndex;
  if(Order == SORT_ASCENDING)
  {
    for(;InsertionIndex < Size;
        ++InsertionIndex)
    {
      CandidateIndex = InsertionIndex;
      while(CandidateIndex > 0 &&
            Array[CandidateIndex - 1] > Array[CandidateIndex])
      {
        i64 SavedElement = Array[CandidateIndex];
        Array[CandidateIndex] = Array[CandidateIndex - 1];
        Array[CandidateIndex - 1] = SavedElement;
        --CandidateIndex;
      }
    }
  }else if(Order == SORT_DESCENDING)
  {
    for(;InsertionIndex < Size;
        ++InsertionIndex)
    {
      CandidateIndex = InsertionIndex;
      while(CandidateIndex > 0 &&
            Array[CandidateIndex - 1] < Array[CandidateIndex])
      {
        i64 SavedElement = Array[CandidateIndex];
        Array[CandidateIndex] = Array[CandidateIndex - 1];
        Array[CandidateIndex - 1] = SavedElement;
        --CandidateIndex;
      }
    }
  }
}

static void
SelectionSort(i64 *Array, i64 Size, i32 Order)
{
  ssize_t ElementIndex = 0, SelectionIndex, SelectedIndex;
  i64 SelectedValue;
  if(Order == SORT_ASCENDING)
  {
    for(;ElementIndex < Size;
      ++ElementIndex)
    {
      SelectedIndex = ElementIndex;
      for(SelectionIndex = ElementIndex + 1;
        SelectionIndex < Size;
        ++SelectionIndex)
        {
          if(Array[SelectedIndex] > Array[SelectionIndex])
          {
            SelectedIndex = SelectionIndex;
          }
        }
        i64 SavedValue = Array[SelectedIndex];
        Array[SelectedIndex] = Array[ElementIndex];
        Array[ElementIndex] = SavedValue;
    }
  }else if(Order == SORT_DESCENDING)
  {
    for(;ElementIndex < Size;
      ++ElementIndex)
    {
      SelectedIndex = ElementIndex;
      for(SelectionIndex = ElementIndex + 1;
        SelectionIndex < Size;
        ++SelectionIndex)
        {
          if(Array[SelectedIndex] < Array[SelectionIndex])
          {
            SelectedIndex = SelectionIndex;
          }
        }
        i64 SavedValue = Array[SelectedIndex];
        Array[SelectedIndex] = Array[ElementIndex];
        Array[ElementIndex] = SavedValue;
    }
  }
}

static void
ShellSort(i64 *Array, i64 Size, i32 Order)
{
  ssize_t GapSize = Size/2, GapIndex, ElementIndex;
  if(Order == SORT_ASCENDING)
  {
    for(;GapSize > 0; GapSize /= 2)
    {
      for(GapIndex = GapSize;
          GapIndex < Size;
          ++GapIndex)
      {
        for(ElementIndex = GapIndex - GapSize;
            ElementIndex >= 0 &&
            Array[ElementIndex] > Array[ElementIndex + GapSize];
            ElementIndex -= GapSize)
        {
          i64 SavedValue = Array[ElementIndex];
          Array[ElementIndex] = Array[ElementIndex + GapSize];
          Array[ElementIndex + GapSize] = SavedValue;
        }
      }
    }
  }else if(Order == SORT_DESCENDING)
  {
    for(;GapSize > 0; GapSize /= 2)
    {
      for(GapIndex = GapSize;
          GapIndex < Size;
          ++GapIndex)
      {
        for(ElementIndex = GapIndex - GapSize;
            ElementIndex >= 0 &&
            Array[ElementIndex] < Array[ElementIndex + GapSize];
            ElementIndex -= GapSize)
        {
          i64 SavedValue = Array[ElementIndex];
          Array[ElementIndex] = Array[ElementIndex + GapSize];
          Array[ElementIndex + GapSize] = SavedValue;
        }
      }
    }
  }
}

static void
_MergeSortMerge(i64 *Array, i64 *SortedArray, i64 Left, i64 RightStart, i64 Right)
{
  i64 LeftEnd = RightStart - 1, ElementCount = (Right - Left + 1), SortedIndex = Left;
  i64 LeftIndex = Left, RightIndex = RightStart;
  while(LeftIndex <= LeftEnd && RightIndex <= Right)
  {
    if(Array[LeftIndex] <= Array[RightIndex])
    {
      SortedArray[SortedIndex] = Array[LeftIndex];
      ++SortedIndex; ++LeftIndex;
    }else
    {
      SortedArray[SortedIndex] = Array[RightIndex];
      ++SortedIndex; ++RightIndex;
    }
  }
  while(LeftIndex <= LeftEnd)
  {
    SortedArray[SortedIndex] = Array[LeftIndex];
    ++SortedIndex; ++LeftIndex;
  }
  while(RightIndex <= Right)
  {
    SortedArray[SortedIndex] = Array[RightIndex];
    ++SortedIndex; ++RightIndex;
  }
  for(i64 ArrayIndex = 0;
      ArrayIndex < ElementCount;
      ++ArrayIndex)
  {
    Array[Right] = SortedArray[Right];
    --Right;
  }
}

static void
_MergeSortSplit(i64 *Array, i64 *SortedArray, i64 Left, i64 Right)
{
  i64 Middle;
  if(Right > Left)
  {
    Middle = (Right + Left)/2;
    _MergeSortSplit(Array, SortedArray, Left, Middle);
    _MergeSortSplit(Array, SortedArray, Middle + 1, Right);
    _MergeSortMerge(Array, SortedArray, Left, Middle + 1, Right);
  }
}

static void
MergeSort(i64 *Array, i64 *SortedArray, i64 Size)
{
  _MergeSortSplit(Array, SortedArray, 0, Size - 1);
}

static void
QuickSort(i64 *Array, i64 Left, i64 Right)
{
  i64 LeftIndex = Left, RightIndex = Right;
  i64 Pivot = Array[(Left + Right)/2];
  while(LeftIndex <= RightIndex)
  {
    while(Array[LeftIndex] < Pivot)
    {
      ++LeftIndex;
    }
    while(Array[RightIndex] > Pivot)
    {
      --RightIndex;
    }
    if(LeftIndex <= RightIndex)
    {
      i64 SavedValue = Array[LeftIndex];
      Array[LeftIndex] = Array[RightIndex];
      Array[RightIndex] = SavedValue;
      ++LeftIndex; --RightIndex;
    }
  }
  if(Left < RightIndex)
  {
    QuickSort(Array, Left, RightIndex);
  }
  if(Right > LeftIndex)
  {
    QuickSort(Array, LeftIndex, Right);
  }
}
