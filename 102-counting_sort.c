#include "sort.h"

/**
 * find_max - a func that gets the maximum value in an arr
 * @array: the array arguments of ints
 * @size: the size/len of the arr arguments
 * Return: the max number in the arr
 */
int find_max(int *array, int size)
{
	int large, nm;

	for (large = array[0], nm = 1; nm < size; nm++)
	{
		if (array[nm] > large)
		{
			large = array[nm];
		}
	}

	return (large);
}

/**
 * counting_sort - a func that sorts an array in ascending order using
 * the counting sort algo
 * @array: the array arguments
 * @size: the size/len of the array arguments
 * Return: void(nothing)
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *srt, large, i;

	if (array == NULL || size < 2)
		return;
	srt = malloc(sizeof(int) * size);
	if (srt == NULL)
		return;
	large = find_max(array, size);
	counter = malloc(sizeof(int) * (large + 1));
	if (counter == NULL)
	{
		free(srt);
		return;
	}
	for (i = 0; i < (large + 1); i++)
	{
		counter[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{
		counter[array[i]] += 1;
	}
	for (i = 0; i < (large + 1); i++)
	{
		counter[i] += counter[i - 1];
	}
	print_array(counter, large + 1);
	for (i = 0; i < (int)size; i++)
	{
		srt[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = srt[i];
	}
	free(srt);
	free(counter);
}
