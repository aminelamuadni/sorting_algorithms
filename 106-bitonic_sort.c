#include "sort.h"

/**
 * bitonic_swap - Swaps two elements in the array based on a condition.
 * @arr: Array of integers.
 * @a: First index to consider.
 * @b: Second index to consider.
 * @dir: Order flag: 1 for ascending and 0 for descending.
 */
void bitonic_swap(int arr[], int a, int b, int dir)
{
	int temp;

	if (dir == (arr[a] > arr[b]))
	{
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}

/**
 * bitonic_merge - Merges array elements in bitonic sequence.
 * @arr: Array of integers.
 * @start: Starting index.
 * @count: Number of elements.
 * @dir: Order flag.
 */
void bitonic_merge(int arr[], int start, int count, int dir)
{
	int middle, i;

	if (count <= 1)
		return;

	middle = count / 2;
	for (i = start; i < start + middle; i++)
		bitonic_swap(arr, i, i + middle, dir);

	bitonic_merge(arr, start, middle, dir);
	bitonic_merge(arr, start + middle, middle, dir);
}

/**
 * bitonic_sort_recursion - Recursively sorts the array in bitonic sequence.
 * @arr: Array of integers.
 * @start: Starting index.
 * @count: Number of elements.
 * @dir: Order flag.
 * @total_size: Total size of the original array for printing.
 */
void bitonic_sort_recursion(int arr[], int start, int count,
							int dir, int total_size)
{
	int middle;

	if (count <= 1)
		return;

	printf("Merging [%i/%i] (%s):\n", count, total_size, dir ? "UP" : "DOWN");
	print_array(&arr[start], count);

	middle = count / 2;
	bitonic_sort_recursion(arr, start, middle, 1, total_size);
	bitonic_sort_recursion(arr, start + middle, middle, 0, total_size);
	bitonic_merge(arr, start, count, dir);

	printf("Result [%i/%i] (%s):\n", count, total_size, dir ? "UP" : "DOWN");
	print_array(&arr[start], count);
}

/**
 * bitonic_sort - Main function to sort array using bitonic sort.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursion(array, 0, size, 1, size);
}
