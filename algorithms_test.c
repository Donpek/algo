#define HUGE_AMOUNT 1000000

static void
TestInsertionSort(i32 Order)
{
  printf("\tINSERTION SORT TEST\n"
         "\tUnsorted:\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, HUGE_AMOUNT);
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  struct timeval SortStart, SortEnd;
  gettimeofday(&SortStart, 0);
  InsertionSort(HugeArray, HUGE_AMOUNT, Order);
  gettimeofday(&SortEnd, 0);
  double TimeElapsed =
    (double)(SortEnd.tv_usec - SortStart.tv_usec) / 1000000 +
    (double)(SortEnd.tv_sec - SortStart.tv_sec);

  printf("\tSorted:\n");
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
  printf("\tSorting time:%f\n", TimeElapsed);
}

static void
TestSelectionSort(i32 Order)
{
  printf("\tSELECTION SORT TEST\n"
         "\tUnsorted:\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, HUGE_AMOUNT);
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  struct timeval SortStart, SortEnd;
  gettimeofday(&SortStart, 0);
  SelectionSort(HugeArray, HUGE_AMOUNT, Order);
  gettimeofday(&SortEnd, 0);
  double TimeElapsed =
    (double)(SortEnd.tv_usec - SortStart.tv_usec) / 1000000 +
    (double)(SortEnd.tv_sec - SortStart.tv_sec);

  printf("\tSorted:\n");
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
  printf("\tSorting time:%f\n", TimeElapsed);
}

static void
TestShellSort(i32 Order)
{
  printf("\tSELECTION SORT TEST\n"
         "\tUnsorted:\n");
  i64 *HugeArray = malloc(sizeof(i64) * HUGE_AMOUNT);
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    HugeArray[HugeIndex] = RangeI64(0, HUGE_AMOUNT);
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }

  struct timeval SortStart, SortEnd;
  gettimeofday(&SortStart, 0);
  ShellSort(HugeArray, HUGE_AMOUNT, Order);
  gettimeofday(&SortEnd, 0);
  double TimeElapsed =
    (double)(SortEnd.tv_usec - SortStart.tv_usec) / 1000000 +
    (double)(SortEnd.tv_sec - SortStart.tv_sec);

  printf("\tSorted:\n");
  for(i32 HugeIndex = 0;
      HugeIndex < HUGE_AMOUNT;
      ++HugeIndex)
  {
    printf("%d: %lli\n", HugeIndex, HugeArray[HugeIndex]);
  }
  printf("\tSorting time:%f\n", TimeElapsed);
}
