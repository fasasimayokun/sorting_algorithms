#include "sort.h"
/**
 * selection_sort - a func that sorts an arr of ints in
 * ascending order using the Selection sort algorithm
 * @array: the arr to sort
 * @size: the size/len of the arr
 * Return: void(nothing)
 */
void selection_sort(int *array, size_t size)
{
	size_t nm, m, l;
	int aux;

	if (!array || !size)
	{
		return;
	}
	for (nm = 0; nm < size - 1; nm++)
	{
		for (m = size - 1, l = nm + 1; m > nm; m--)
		{
			if (array[m] < array[l])
			{
				l = m;
			}
		}
		if (array[nm] > array[l])
		{
			aux = array[nm];
			array[nm] = array[l];
			array[l] = aux;
			print_array(array, size);
		}
	}
}
