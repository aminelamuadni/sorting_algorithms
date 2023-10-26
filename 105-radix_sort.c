#include "sort.h"

/**
 * max_value - Return max value in array.
 * @array: The array.
 * @size: Size of the array.
 * Return: The maximum value.
 */
int max_value(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Perform counting sort based on digit position.
 * @array: The array.
 * @size: Size of the array.
 * @position: The digit position.
 */
void counting_sort_radix(int *array, size_t size, int position)
{
	int *output = malloc(sizeof(int) * size);
	int i, count[10] = {0};

	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / position) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / position) % 10] - 1] = array[i];
		count[(array[i] / position) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int position;

	if (!array || size <= 1)
		return;

	max = max_value(array, size);

	for (position = 1; max / position > 0; position *= 10)
	{
		counting_sort_radix(array, size, position);
		print_array(array, size);
	}
}
