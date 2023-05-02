#include "lists.h"


/**
 * delete_nodeint_at_index - deletes the node at index of
 * a listint_t linked list
 * @head: head of linked list.
 * @index: index of node to be deleted
 *
 * Return: 1 if success and -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *prev;
	unsigned int p = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		return (1);
	}

	prev = *head;
	current = (*head)->next;

	while (current != NULL && p < index)
	{
		prev = current;
		current = current->next;

		p++;
	}

	if (p == index && current != NULL)
	{
		prev->next = current->next;
		free(current);
		return (1);
	}

	return (-1);
}
