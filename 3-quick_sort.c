#include "sort.h"

/**
 * swap - a func that swaps two numbers
 * @array: the int arr to sort
 * @size: the size/len of the arr
 * @x: the addrs of the 1st value
 * @y: the addrs of the second value
 * Return: void(nothing)
 */
void swap(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition_schim - a func that partitions the arr int sub arrays
 * @array: the int arr to partition and sort
 * @size: the size/len of the array
 * @lb: the lower bound index of the sort range
 * @hb: the higher bound index of the sort range
 * Return: size_t
 */
size_t lomuto_partition_schim(int *array, size_t size, ssize_t lb, ssize_t hb)
{
	int nm, m, key = array[hb];

	for (nm = m = lb; m < hb; m++)
	{
		if (array[m] < key)
			swap(array, size, &array[m], &array[nm++]);
	}
	swap(array, size, &array[nm], &array[hb]);
	return (nm);
}

/**
 * _quicksorts - a func that quicksorts via the lomuto partitioning schim
 * @array: the int arr to sort
 * @size: the size/len of the arr
 * @lb: the lowr bound index of the sort range
 * @hb: the higher bound index of the sort range
 * Return: void(nothing)
 */
void _quicksorts(int *array, size_t size, ssize_t lb, ssize_t hb)
{
	if (lb < hb)
	{
		size_t pt = lomuto_partition_schim(array, size, lb, hb);

		_quicksorts(array, size, lb, pt - 1);
		_quicksorts(array, size, pt + 1, hb);
	}
}

/**
 * quick_sort - a func that sorts an arr of ints
 * in ascending order using the Quick sort algorithm by calling quicksorts
 * @array: the int arr to sort
 * @size: the size/len of the array argument
 * Return: void(nothing)
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}
	_quicksorts(array, size, 0, size - 1);
}
