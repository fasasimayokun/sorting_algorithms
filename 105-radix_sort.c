#include "sort.h"

/**
 * find_max - a func that gets the maximum value in an array
 * @array: the array argument
 * @size: the size/len of the arr argument
 * Return: int (the max value in the arr)
 */
int find_max(int *array, int size)
{
	int large, nm;

	for (large = array[0], nm = 1; nm < size; nm++)
	{
		if (array[nm] > large)
			large = array[nm];
	}
	return (large);
}

/**
 * radix_counting_sort -  a func that sorts the significant digits of an arr
 * in ascending order using the counting sort algo
 * @array: the arr argument
 * @size: the size/len of the arr argument
 * @signif: the significant digit to sort with
 * @buf: the buffer to store the array sorted
 * Return: void(nothing)
 */
void radix_counting_sort(int *array, size_t size, int signif, int *buf)
{
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t nm;

	for (nm = 0; nm < size; nm++)
	{
		counter[(array[nm] / signif) % 10] += 1;
	}
	for (nm = 0; nm < 10; nm++)
	{
		counter[nm] += counter[nm - 1];
	}
	for (nm = size - 1; (int)nm >= 0; nm--)
	{
		buf[counter[(array[nm] / signif) % 10] - 1] = array[nm];
		counter[(array[nm] / signif) % 10] -= 1;
	}
	for (nm = 0; nm < size; nm++)
		array[nm] = buf[nm];
}

/**
 * radix_sort - a func that sort an array in ascending order using
 * the radix sort algorithm
 * @array: the array argument
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void radix_sort(int *array, size_t size)
{
	int large, signif, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	large = find_max(array, size);
	for (signif = 1; large / signif > 0; signif *= 10)
	{
		radix_counting_sort(array, size, signif, buf);
		print_array(array, size);
	}

	free(buf);
}
