#include "search_algos.h"

/**
 * linear_skip - looks for a specific value in a sorted skip list of integers
 * @list: pointer to first node of a sorted skip list
 * @value: value to be found in list
 * Return: pointer to first node where value can be found, or NULL if it can't
 * be found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *back, *forward;

	if (list == NULL)
		return (NULL);
	back = forward = list;
	if (forward->express != NULL)
		forward = forward->express;
	while (forward->next != NULL)
	{
		printf("Value checked at index [%lu] = [%i]\n",
				forward->index, forward->n);
		if (forward->n >= value)
			break;
		back = forward;
		if (forward->express != NULL)
			forward = forward->express;
		else
		{
			while (forward->next != NULL)
				forward = forward->next;
		}
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
