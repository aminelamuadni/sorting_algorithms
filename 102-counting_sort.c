#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *				 using the Counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Void.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, idx, j;
	int *counting_array, *output;

	if (!array || size < 2)
		return;

	for (idx = 0; idx < (int)size; idx++)
	{
		if (array[idx] > max)
			max = array[idx];
	}

	counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;
	for (idx = 0; idx <= max; idx++)
		counting_array[idx] = 0;

	for (idx = 0; idx < (int)size; idx++)
		counting_array[array[idx]]++;

	for (idx = 1; idx <= max; idx++)
		counting_array[idx] += counting_array[idx - 1];

	for (idx = 0; idx <= max; idx++)
	{
		if (idx < max)
			printf("%d, ", counting_array[idx]);
		else
			printf("%d\n", counting_array[idx]);
	}

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
