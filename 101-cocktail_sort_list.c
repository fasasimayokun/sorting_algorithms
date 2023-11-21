#include <stdbool.h>
#include "sort.h"

/**
 * swap_node_before -  a func that swaaps a node in a
 * double linked list with the node before it
 * @head: the ptr to the head of the double linked list
 * @tail: the addrs to the tail of the double linked list
 * @shaker: the ptr to the present swaping node
 */
void swap_node_before(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *aux = (*shaker)->next;

	if ((*shaker)->prev != NULL)
	{
		(*shaker)->prev->next = aux;
	}
	else
	{
		*head = aux;
	}
	aux->prev = (*shaker)->prev;
	(*shaker)->next = aux->next;
	if (aux->next != NULL)
	{
		aux->next->prev = *shaker;
	}
	else
	{
		*tail = *shaker;
	}
	(*shaker)->prev = aux;
	aux->next = *shaker;
	*shaker = aux;
}

/**
 * swap_node_at_back - a func that swaps a node in a double
 * linked list with the node behind it
 * @head: the addrs to the head of the double linked list
 * @tail: the addrs to the taill of the double linked list
 * @shaker: the addrs to the present swapping node of the cocktal algo
 * Return: void(nothing)
 */
void swap_node_at_back(listint_t **head, listint_t **tail, listint_t **shaker)
{
	listint_t *aux = (*shaker)->prev;

	if ((*shaker)->next != NULL)
	{
		(*shaker)->next->prev = aux;
	}
	else
	{
		*tail = aux;
	}
	aux->next = (*shaker)->next;
	(*shaker)->prev = aux->prev;
	if (aux->prev != NULL)
	{
		aux->prev->next = *shaker;
	}
	else
	{
		*head = *shaker;
	}
	(*shaker)->next = aux;
	aux->prev = *shaker;
	*shaker = aux;
}

/**
 * cocktail_sort_list - a func that sorts a double linked list of type
 * listint_t in ascending order using the cocktail shaker algo
 * @list: the addrs to the head of the double linkedlist
 * Return: void(nothing)
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *shaker;
	listint_t *tail;
	bool shaker_not_stird = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
	{
		tail = tail->next;
	}

	while (shaker_not_stird == false)
	{
		shaker_not_stird = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_before(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaker_not_stird = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_at_back(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaker_not_stird = false;
			}
		}
	}
}
