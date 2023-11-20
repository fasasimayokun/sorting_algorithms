#include "sort.h"
/**
 * bubble_sort - a func that sort an arr of ints in
 * ascending order using the Bubble sort algorithm
 * @array: the arr of ints arguments
 * @size: the size/len of the array 
 * Return: void(nothing)
 */
void bubble_sort(int *array, size_t size)
{
	int aux;
	size_t nm, m;

	if (!array || !size)
		return;

	nm = 0;
	while (nm < size)
	{
		for (m = 0; m < size - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				aux = array[m];
				array[m] = array[m + 1];
				array[m + 1] = aux;
				print_array(array, size);
			}
		}
		nm++;
	}
}
