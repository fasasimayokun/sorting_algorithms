#include "sort.h"
#define super(x) (((x) - 1) / 2)
#define leftsub(x) (((x) * 2) + 1)

/**
 * swap - a func that swaps two int vals
 * @array: the int arr argument to sort
 * @size: the size/len of thearr argument
 * @x: addrs of the 1st val
 * @y: the addrs of the 2nd val
 * Return: void(nothing)
 */
void swap(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
	}
	print_array((const int *)array, size);
}

/**
 * siftdown - a func that uses the siftdwon implementation
 * @array: the arr argument to sort
 * @begin: the start of the arr argument
 * @end: the stop of the array argument
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void siftdown(int *array, size_t begin, size_t end, size_t size)
{
	size_t rut = begin, sswap, sub;

	while (leftsub(rut) <= end)
	{
		sub = leftsub(rut);
		sswap = rut;
		if (array[sswap] < array[sub])
		{
			sswap = sub;
		}
		if (sub + 1 <= end && array[sswap] < array[sub + 1])
		{
			sswap = sub + 1;
		}
		if (sswap == rut)
			return;
		swap(array, size, &array[rut], &array[sswap]);
		rut = sswap;
	}
}

/**
 * heapify - a func that makes a heap in place
 * @array: the arr argument to sort
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void heapify(int *array, size_t size)
{
	ssize_t begin;

	begin = super(size - 1);
	while (begin >= 0)
	{
		siftdown(array, begin, size - 1, size);
		begin--;
	}
}

/**
 * heap_sort - a func that uses the heap sort algorithm
 * @array: the arr argument to sort
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void heap_sort(int *array, size_t size)
{
	size_t stop;

	if (!array || size < 2)
		return;
	heapify(array, size);
	stop = size - 1;
	while (stop > 0)
	{
		swap(array, size, &array[stop], &array[0]);
		stop--;
		siftdown(array, 0, stop, size);
	}
}
