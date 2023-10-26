#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: Array to sort.
 * @l: Left array.
 * @r: Right array.
 * @size: Size of @array.
 */
void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int lsize = size / 2, rsize = size - lsize;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, lsize);
	printf("[right]: ");
	print_array(r, rsize);

	while (i < lsize && j < rsize)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < lsize)
		array[k++] = l[i++];

	while (j < rsize)
		array[k++] = r[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: Array to sort.
 * @size: Size of @array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *l, *r;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;
	l = malloc(mid * sizeof(int));
	r = malloc((size - mid) * sizeof(int));

	if (!l || !r)
	{
		free(l);
		free(r);
		return;
	}

	for (i = 0; i < mid; i++)
		l[i] = array[i];
	for (i = 0; i < size - mid; i++)
		r[i] = array[i + mid];

	merge_sort(l, mid);
	merge_sort(r, size - mid);
	merge(array, l, r, size);

	free(l);
	free(r);
}
