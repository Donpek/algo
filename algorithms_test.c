static void
TestInsertionSort(i32 Order)
{
  printf("\tINSERTION SORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  clock_t Start, End;
  Start = clock();
  InsertionSort(HugeArray, HUGE_AMOUNT, Order);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;

  // printf("Sorted:\n");
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}

static void
TestSelectionSort(i32 Order)
{
  printf("\tSELECTION SORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  clock_t Start, End;
  Start = clock();
  SelectionSort(HugeArray, HUGE_AMOUNT, Order);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;

  // printf("Sorted:\n");
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}

static void
TestShellSort(i32 Order)
{
  printf("\tSHELLSORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    // HugeArray[HugeIndex] = HugeIndex;
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  clock_t Start, End;
  Start = clock();
  ShellSort(HugeArray, HUGE_AMOUNT, Order);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;

  // printf("Sorted:\n");
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      HugeIndex += HUGE_AMOUNT/1000)
  {
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}

static void
TestMergeSort(void)
{
  printf("\tMERGE SORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  i64 *SortedArray = calloc(HUGE_AMOUNT, sizeof(i64));
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    // HugeArray[HugeIndex] = HugeIndex;
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  clock_t Start, End;
  Start = clock();
  MergeSort(HugeArray, SortedArray, HUGE_AMOUNT);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;

  // printf("Sorted:\n");
  for(i32 SortedIndex = 0;
      SortedIndex < HUGE_AMOUNT;
      SortedIndex += HUGE_AMOUNT/1000)
  {
    // printf("%d: %lli\n", SortedIndex, HugeArray[SortedIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}

static void
TestQuickSort(void)
{
  printf("\tQUICKSORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    // HugeArray[HugeIndex] =  HugeIndex;
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  clock_t Start, End;
  Start = clock();
  QuickSort(HugeArray, 0, HUGE_AMOUNT - 1);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;
  
  // printf("Sorted:\n");
  for(i32 SortedIndex = 0;
      SortedIndex < HUGE_AMOUNT;
      SortedIndex += HUGE_AMOUNT/1000)
  {
    // printf("%d: %lli\n", SortedIndex, HugeArray[SortedIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}

static void
TestHeapSort(void)
{
  printf("\tHEAPSORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    // HugeArray[HugeIndex] =  HugeIndex;
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  clock_t Start, End;
  Start = clock();
  HeapSort(HugeArray, HUGE_AMOUNT);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;

  // printf("Sorted:\n");
  for(i32 SortedIndex = 0;
      SortedIndex < HUGE_AMOUNT;
      SortedIndex += HUGE_AMOUNT/10000)
  {
    // printf("%d: %lli\n", SortedIndex, HugeArray[SortedIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}

static void
TestRadixSort(void)
{
  printf("\tRADIXSORT TEST\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, RANDOM_MAX);
    // HugeArray[HugeIndex] =  HugeIndex;
    // printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
	
  clock_t Start, End;
  Start = clock();
  RadixSort(HugeArray, HUGE_AMOUNT);
  End = clock();
  double TimeElapsed = (double)(End-Start)/CLOCKS_PER_SEC;
  
  // printf("Sorted:\n");
  for(i32 SortedIndex = 0;
      SortedIndex < HUGE_AMOUNT;
      SortedIndex += 1)
  {
    printf("%d: %lli\n", SortedIndex, HugeArray[SortedIndex]);
  }
  printf("Sorting time:%f\n", TimeElapsed);
}
