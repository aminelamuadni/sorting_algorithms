#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @size: Size of the full original array (needed for print_array).
 * @lo: The lower index of the sub-array.
 * @hi: The higher index of the sub-array.
 *
 * Return: The final index of the pivot.
 */
int lomuto_partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo, j;
	int temp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] != array[i])
	{
		temp = array[i];
		array[i] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_quick_sort - Recursively sorts an array using the quicksort
 * algorithm and Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: Size of the full original array (needed for print_array).
 * @lo: The lower index of the sub-array.
 * @hi: The higher index of the sub-array.
 */
void lomuto_quick_sort(int *array, size_t size, int lo, int hi)
{
	int pivot;

	if (lo < hi)
	{
		pivot = lomuto_partition(array, size, lo, hi);
		lomuto_quick_sort(array, size, lo, pivot - 1);
		lomuto_quick_sort(array, size, pivot + 1, hi);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_quick_sort(array, size, 0, size - 1);
}
