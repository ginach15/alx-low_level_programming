#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: points at the beginning of a linked list
 * @index: node at this index is to be deleted
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current = *head;

	if ((current == NULL) || (head == NULL))
		return (-1);
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
	}
	else if (index > 0)
	{
		for (i = 0; (i < index) && (current != NULL); i++)
			current = current->next;
		if (i == index)
		{
			if (current->next == NULL)
				current->prev->next = NULL;
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
		}
		else
			return (-1);
	}
	free(current);
	return (1);
}
