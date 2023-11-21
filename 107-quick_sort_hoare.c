#include "sort.h"

/**
 * swap_nums - a func that swaps 2 ints in arr
 * @x: the 1st int value to swap
 * @y: the 2nd int value to swap
 * Return: void(nothing)
 */
void swap_nums(int *x, int *y)
{
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

/**
 * hoare_partition_schim -  a func that orders a subset of an arr
 * according to the hoare partition scheme
 * @array: the array argument
 * @size: the size/len of the arr argument
 * @begin: the start position of the subet
 * @end: the end position of the subset
 * Return: int(the finall partition index)
 */
int hoare_partition_schim(int *array, size_t size, int begin, int end)
{
	int top, pivt, bottom;

	pivt = array[end];
	for (top = begin - 1, bottom = end + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < pivt);
		do {
			bottom--;
		} while (array[bottom] > pivt);

		if (top < bottom)
		{
			swap_nums(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - a func that implements the quick sort algo thru recursion
 * @array: the array argument
 * @size: the size/len of the arr argument
 * @begin: the start position of the array partition
 * @end: the end positon of the array partition
 * Return: void(nothing)
 */
void hoare_sort(int *array, size_t size, int begin, int end)
{
	int prt;

	if (end - begin > 0)
	{
		prt = hoare_partition_schim(array, size, begin, end);
		hoare_sort(array, size, begin, prt - 1);
		hoare_sort(array, size, prt, end);
	}
}

/**
 * quick_sort_hoare - a func that sorts an arr in ascending
 * order using the quicksort algorithm
 * @array: the arr argument
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
