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
