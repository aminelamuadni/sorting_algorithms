#include "sort.h"
#include <stddef.h>

/**
 * hoare_swap - Swaps two elements in an array.
 * @arr: A pointer to the array.
 * @a: Index of the first element.
 * @b: Index of the second element.
 */
void hoare_swap(int *arr, size_t a, size_t b)
{
	int t;

	t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

/**
 * hoare_partition - Partitions an array using Hoare's scheme.
 * @arr: A pointer to the array.
 * @start: The starting index.
 * @end: The ending index.
 * @len: The length of the array.
 *
 * Return: New pivot position.
 */
size_t hoare_partition(int *arr, ssize_t start, ssize_t end, int len)
{
	int ref_val = arr[end];
	ssize_t i = start - 1, j = end + 1;

	while (1)
	{
		do {
			i++;
		} while (arr[i] < ref_val);

		do {
			j--;
		} while (arr[j] > ref_val);

		if (i >= j)
			return (i);

		hoare_swap(arr, i, j);
		print_array(arr, len);
	}
}

/**
 * hoare_sort - A recursive function to sort the elements.
 * @arr: A pointer to the array.
 * @start: The starting index.
 * @end: The ending index.
 * @len: The length of the array.
 */
void hoare_sort(int *arr, ssize_t start, ssize_t end, int len)
{
	ssize_t pi;

	if (start < end)
	{
		pi = hoare_partition(arr, start, end, len);
		hoare_sort(arr, start, pi - 1, len);
		hoare_sort(arr, pi, end, len);
	}
}

/**
 * quick_sort_hoare - sorts an array using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}
