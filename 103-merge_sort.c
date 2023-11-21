#include "sort.h"

/**
 * merge_cmp - a func that compares the two merges
 * @array: the int arr argument
 * @begin: the starting index
 * @cen: the mid index
 * @end: the ending index
 * @res: the output arr argument
 * Return: void(nothing)
 */
void merge_cmp(int *array, int *res, size_t begin, size_t cen, size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, cen - begin);
	printf("[right]: ");
	print_array(array + cen, end - cen);

	for (i = begin, j = cen; i < cen && j < end; k++)
		res[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < cen; i++)
		res[k++] = array[i];
	for (; j < end; j++)
		res[k++] = array[j];
	for (i = begin, k = 0; i < end; i++)
		array[i] = res[k++];
	printf("[Done]: ");
	print_array(array + begin, end - begin);
}

/**
 * merge_sort_up_bottom - a fun that sorts from top to dowm recursively
 * @array: the int array argument to sort
 * @begin: the starting index
 * @end: the ending index
 * @res: the output arr argument
 * Return: void(nothing)
 */
void merge_sort_up_bottom(int *array, int *res, size_t begin, size_t end)
{
	size_t cen;

	if (end - begin > 1)
	{
		cen = begin + (end - begin) / 2;
		merge_sort_up_bottom(array, res, begin, cen);
		merge_sort_up_bottom(array, res, cen, end);
		merge_cmp(array, res, begin, cen, end);
	}
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

	if (!array || size < 2)
		return;
	nw = malloc(sizeof(int) * size);
	if (nw == NULL)
	{
		return;
	}
	merge_sort_up_bottom(array, nw, 0, size);
	free(nw);
}
