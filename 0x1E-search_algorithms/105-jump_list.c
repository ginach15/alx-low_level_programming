#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a sorted list of integers using the
 * jump search algorithm
 * @list: pointer to first node of a singly linked list
 * @size: number of nodes in linked list
 * @value: value to be found in linked list
 * Return: pointer to first node where value is located, or NULL if it is not
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *back, *forward;
	unsigned int r, i;

	if (list == NULL)
		return (NULL);
	if (size == 0)
		return (NULL);
	r = sqrt(size);
	forward = list;
	back = forward;
	for (i = forward->index + r; forward->index < i &&
			forward->next != NULL; forward = forward->next)
		;
	while (forward->next != NULL)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				forward->index, forward->n);
		if (forward->n > value)
			break;
		back = forward;
		for (i = forward->index + r; forward->index < i &&
				forward->next != NULL; forward = forward->next)
			;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			back->index, forward->index);
	for (; back->index <= forward->index; back = back->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				back->index, back->n);
		if (back->n == value)
			return (back);
		else if (back->n > value)
			break;
	}
	return (NULL);
}
