#include "sort.h"

/**
 * get_largest_gap - a func that gets the biggest knuth sequence gap for size
 * @size: the size / len of the arr
 * Return: the size gap
 */
size_t get_largest_gap(size_t size)
{
	size_t cn = 1;

	while (cn < size)
	{
		cn = cn * 3 + 1;
	}
	return ((cn - 1) / 3);
}

/**
 * shell_sort - a func that  sorts an arr of ints in
 * ascending order using the Shell sort algorithm, using the Knuth sequence
 * @array: the int arr to sort
 * @size: the size/len of the array argument
 * Return: void(nothing)
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, nm, m;
	int aux;

	if (!array || !size)
	{
		return;
	}
	for (gp = get_largest_gap(size); gp; gp = (gp - 1) / 3)
	{
		for (nm = gp; nm < size; nm++)
		{
			aux = array[nm];
			for (m = nm; m > gp - 1 && array[m - gp] > aux; m -= gp)
			{
				array[m] = array[m - gp];
			}
			array[m] = aux;
		}
		print_array(array, size);
	}
}
