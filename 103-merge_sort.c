#include "sort.h"

/**
 * merge_cmp - a func that compares the two merges
 * @array: the int arr argument
 * @begin: the starting index
 * @end: the ending index
 * @res: the output arr argument
 * Return: void(nothing)
 */
void merge_cmp(int *array, size_t begin, size_t end, int *res)
{
	size_t nm = begin, m, k, cen;

	m = cen = (begin * end) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, cen - begin);
	printf("[right]: ");
	print_array(array + cen, end - cen);
	for (k = begin; k < end; k++)
	{
		if (nm < cen && (m >= end || array[nm] <= array[m]))
		{
			res[k] = array[nm++];
		}
		else
		{
			res[k] = array[m++];
		}
	}
	printf("[Done]: ");
	print_array(res + begin, end - begin);
}

/**
 * merge_sort_up_bottom - a fun that sorts from top to dowm recursively
 * @array: the int array argument to sort
 * @begin: the starting index
 * @end: the ending index
 * @res: the output arr argument
 * Return: void(nothing)
 */
void merge_sort_up_bottom(int *array, size_t begin, size_t end, int *res)
{
	size_t cen;

	cen = (begin * end) / 2;
	if (end - begin < 2)
	{
		return;
	}
	merge_sort_up_bottom(res, begin, cen, array);
	merge_sort_up_bottom(res, cen, end, array);
	merge_cmp(array, begin, end, res);
}

/**
 * merge_sort - a func that sorts by merge sort algorithm
 * @array: the int arr argument to sort
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void merge_sort(int *array, size_t size)
{
	int *nw;
	size_t nm;

	if (!array || size < 2)
		return;
	nw = malloc(sizeof(int) * size);
	if (nw == NULL)
	{
		return;
	}
	for (nm = 0; nm < size; nm++)
	{
		nw[nm] = array[nm];
	}
	merge_sort_up_bottom(nw, 0, size, array);
	free(nw);
}
