#include "deck.h"

/**
 * str_cmp - a func that compares 2 strs
 * @str_1: the 1st str argument to compare
 * @str_2: the 2nd str argument to compare
 * Return: int (0(equal), 1 or -1)
 */
int str_cmp(const char *str_1, const char *str_2)
{
	while (*str_1 && *str_2 && *str_1 == *str_2)
	{
		str_1++;
		str_2++;
	}
	if (*str_1 != *str_2)
		return (*str_1 - *str_2);
	return (0);
}

/**
 * fetch_val - a func that gets the num representation of the card
 * @card: the addrs to the deck_node_t data structure
 * Return: char(the num representation of the card)
 */
char fetch_val(deck_node_t *card)
{
	if (str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (str_cmp(card->card->value, "1") == 0)
		return (1);
	if (str_cmp(card->card->value, "2") == 0)
		return (2);
	if (str_cmp(card->card->value, "3") == 0)
		return (3);
	if (str_cmp(card->card->value, "4") == 0)
		return (4);
	if (str_cmp(card->card->value, "5") == 0)
		return (5);
	if (str_cmp(card->card->value, "6") == 0)
		return (6);
	if (str_cmp(card->card->value, "7") == 0)
		return (7);
	if (str_cmp(card->card->value, "8") == 0)
		return (8);
	if (str_cmp(card->card->value, "9") == 0)
		return (9);
	if (str_cmp(card->card->value, "10") == 0)
		return (10);
	if (str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (str_cmp(card->card->value, "Queen") == 0)
	{
		return (12);
	}
	return (13);
}

/**
 * place_sort_deck_kind - a func that sorts the decks of cards from spades
 * to diamonds
 * @deck: the addrs to the head of the deck_node_t double link data structure
 * Return: void(nothing)
 */
void place_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *seq, *place, *aux;

	for (seq = (*deck)->next; seq != NULL; seq = aux)
	{
		aux = seq->next;
		place = seq->prev;
		while (place != NULL && place->card->kind > seq->card->kind)
		{
			place->next = seq->next;
			if (seq->next != NULL)
				seq->next->prev = place;
			seq->prev = place->prev;
			seq->next = place;
			if (place->prev != NULL)
				place->prev->next = seq;
			else
				*deck = seq;
			place->prev = seq;
			place = seq->prev;
		}
	}
}

/**
 * place_sort_deck_val - a func that sorts the deck of cards sorted
 * from spades to diamonds && from ace to king
 * @deck: the addrs to the head of the deck_node_t double linked data structure
 * Return: void(nothing)
 */
void place_sort_deck_val(deck_node_t **deck)
{
	deck_node_t *place, *seq, *aux;

	for (seq = (*deck)->next; seq != NULL; seq = aux)
	{
		aux = seq->next;
		place = seq->prev;
		while (place != NULL &&
		       place->card->kind == seq->card->kind &&
		       fetch_val(place) > fetch_val(seq))
		{
			place->next = seq->next;
			if (seq->next != NULL)
				seq->next->prev = place;
			seq->prev = place->prev;
			seq->next = place;
			if (place->prev != NULL)
				place->prev->next = seq;
			else
				*deck = seq;
			place->prev = seq;
			place = seq->prev;
		}
	}
}

/**
 * sort_deck - a func that sortthe deck of cars from ace to king
 * && from spades to diamonds
 * @deck: the addrs to the head of the deck_node_t double link list data struct
 * Return: void(nothing)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
	{
		return;
	}
	place_sort_deck_kind(deck);
	place_sort_deck_val(deck);
}
