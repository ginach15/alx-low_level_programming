#include "lists.h"
/**
 * _dlistint_len - the number of elements in a linked list_t list
 * @h: list to browse
 * Return: size of the list
 */
size_t _dlistint_len(const dlistint_t *h)
{
	if (h == NULL)
		return (0);
	else
		return (_dlistint_len(h->next) + 1);
}
/**
 * _get_nodeint_at_index - the nth node of a listint_t linked list
 * @head: first element
 * @index: element's number
 * Return: a node
 */
dlistint_t *_get_nodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int cLoop = 0;

	while (head != NULL)
	{
		if (index == cLoop)
			return (head);
		head = head->next;
		cLoop++;
	}
	return (NULL);
}
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: first elemen
 * @idx: element's number
 * @n: number
 * Return: he address of the new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *before;
	int length;

	new = _createNode(n);
#include "lists.h"
	/**
	 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t
	 *linked list
	 * @head: first element
	 * @index: element's number
	 * Return: error code
	 */
	int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
	{dlistint_t *before, *current;
		unsigned int i = 0;

		current = *head;
		if (current == NULL)
			return (-1);
		if (index == 0)
		{
		*head = current->next;
		current->prev = NULL;
		free(current)
		return (1);
		}
		while (i < index)
		{
			before = current;
			if (current->next == NULL)
				return (-1);
			current = current->next;
			i++;
		}
		before->next = current->next;
		if (current->next != NULL)
			current->next->prev = before;
		free(current);
		return (1);
}
