#include "sort.h"

/**
 * find_max - Find the maximum number in an array.
 * @array: The array.
 * @size: The size of the array.
 * Return: The maximum number in the array.
 */
int find_max(int *array, size_t size)
{
	int max = 0, idx;

	for (idx = 0; idx < (int)size; idx++)
		if (array[idx] > max)
			max = array[idx];
	return (max);
}

/**
 * initialize_counting_array - Initialize and fill the counting array.
 * @max: The maximum number in the array.
 * @array: The original array.
 * @size: The size of the original array.
 * Return: The counting array.
 */
int *initialize_counting_array(int max, int *array, size_t size)
{
	int idx;
	int *counting_array = malloc(sizeof(int) * (max + 1));

	if (!counting_array)
		return (NULL);
	for (idx = 0; idx <= max; idx++)
		counting_array[idx] = 0;
	for (idx = 0; idx < (int)size; idx++)
		counting_array[array[idx]]++;
	return (counting_array);
}

/**
 * print_counting_array - Print the counting array.
 * @counting_array: The counting array.
 * @max: The maximum value in the array.
 */
void print_counting_array(int *counting_array, int max)
{
	int idx;

	for (idx = 0; idx <= max; idx++)
	{
		if (idx < max)
			printf("%d, ", counting_array[idx]);
		else
			printf("%d\n", counting_array[idx]);
	}
}

/**
 * counting_sort - Sorts an array using Counting sort algorithm.
 * @array: The array.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, idx, j;
	int *counting_array, *output;

	if (!array || size < 2)
		return;

	max = find_max(array, size);
	counting_array = initialize_counting_array(max, array, size);
	if (!counting_array)
		return;

	for (idx = 1; idx <= max; idx++)
		counting_array[idx] += counting_array[idx - 1];

	print_counting_array(counting_array, max);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(counting_array);
		return;
	}
	for (idx = size - 1; idx >= 0; idx--)
	{
		output[counting_array[array[idx]] - 1] = array[idx];
		counting_array[array[idx]]--;
	}
	for (j = 0; j < (int)size; j++)
		array[j] = output[j];

	free(counting_array);
	free(output);
}
