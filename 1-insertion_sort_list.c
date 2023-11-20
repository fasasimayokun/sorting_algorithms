#include "sort.h"

/**
 * swap - a func that swaps two nodes in the double linked list
 * data structure
 * @x: the addrs to the 1st node
 * @y: the addrs to the 2nd node
 * Return: void(nothing)
 */
void swap(listint_t *x, listint_t *y)
{
	if (x->prev)
	{
		x->prev->next = y;
	}
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
 * insertion_sort_list - a func that sorts a doubly linked list of
 * ints in ascending order using the Insertion sort algorithm
 * @list: the addrs of the pointer of the head node in the
 * double linked list
 * Return: void(nothing)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nm, *m;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	nm = (*list)->next;
	while (nm)
	{
		m = nm;
		nm = nm->next;
		while (m && m->prev)
		{
			if (m->prev->n > m->n)
			{
				swap(m->prev, m);
				if (!m->prev)
					*list = m;
				print_list((const listint_t *)*list);
			}
			else
			{
				m = m->prev;
			}
		}
	}
}
