#include "sort.h"

#define UP 0
#define DOWN 1

/**
 * swap_nums - a func that swaps 2 ints in an arr
 * @x: the 1st int to swap
 * @y: the 2nd int to swap
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
 * bitonic_join - a func that sorts bitonic sequence in an arr
 * @array: the array argument
 * @size: the size/len of the arr argument
 * @begin: the starting index of the sequence in the arr
 * @iter: the size/len of the sequence to sort
 * @direc: the flow/directiong to sort in
 * Return: void(nothing)
 */
void bitonic_join(int *array, size_t size, size_t begin, size_t iter,
		char direc)
{
	size_t nm, step = iter / 2;

	if (iter > 1)
	{
		for (nm = begin; nm < begin + step; nm++)
		{
			if ((direc == UP && array[nm] > array[nm + step]) ||
			    (direc == DOWN && array[nm] < array[nm + step]))
				swap_nums(array + nm, array + nm + step);
		}
		bitonic_join(array, size, begin, step, direc);
		bitonic_join(array, size, begin + step, step, direc);
	}
}

/**
 * bitonic_iter - a func that converts an arr to a bitonic sequenc
 * @array: the array argument
 * @size: the size/len of the arr argument
 * @begin: the starting index of the bitonic sequence
 * @iter: the size of bitonic sequenc building block
 * @direc: the flow/direction to the bitonic seq
 * Return: void(nothing)
 */
void bitonic_iter(int *array, size_t size, size_t begin, size_t iter,
		char direc)
{
	size_t halv = iter / 2;
	char *st = (direc == UP) ? "UP" : "DOWN";

	if (iter > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", iter, size, st);
		print_array(array + begin, iter);

		bitonic_iter(array, size, begin, halv, UP);
		bitonic_iter(array, size, begin + halv, halv, DOWN);
		bitonic_join(array, size, begin, iter, direc);

		printf("Result [%lu/%lu] (%s):\n", iter, size, st);
		print_array(array + begin, iter);
	}
}

/**
 * bitonic_sort - a func that sort an arr in ascending order
 * using the bitonic sort algorithm
 * @array: the arr argument
 * @size: the size/len of the arr argument
 * Return: void(nothing)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	bitonic_iter(array, size, 0, size, UP);
}
