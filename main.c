#include "algo.h"
int main(void)
{
	srand(time(0));
	// TestLLBST();
	// TestInsertionSort(SORT_ASCENDING);
	// TestSelectionSort(SORT_DESCENDING);
	// TestShellSort(SORT_ASCENDING);
	// TestMergeSort();
	TestQuickSort();
	// TestHeapSort();	
	TestRadixSort();
  return 0;
}
