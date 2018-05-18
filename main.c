#define HUGE_AMOUNT 1000
#define RANDOM_MAX 1000
#include "algo.h"
int main(void)
{
	srand(time(0));
	printf("Sample size: %d\n", HUGE_AMOUNT);
	printf("Data range: 1-%d\n", RANDOM_MAX);
	// TestLLBST();
	// TestInsertionSort(SORT_ASCENDING);
	// TestSelectionSort(SORT_DESCENDING);
	TestShellSort(SORT_ASCENDING);
	TestMergeSort();
	TestQuickSort();
	// TestHeapSort();	
	TestRadixSort();
  return 0;
}
