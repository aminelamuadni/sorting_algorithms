#include "sort.h"

/**
 * swap_ints - Swap two integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turn an array into a max heap.
 * @array: The array.
 * @n: The size of the heap.
 * @i: The current index.
 * @size: Original size of the array.
 */
void heapify(int *array, int n, int i, size_t size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_ints(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 * order using the Heap sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);

		heapify(array, i, 0, size);
	}
}
