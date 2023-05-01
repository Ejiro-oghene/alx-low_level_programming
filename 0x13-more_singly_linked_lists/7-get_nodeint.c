#include "lists.h"


/**
 * get_nodeint_at_index - this returns the nth node of a listint_t linked list
 * @head: pointer to the 1st node of the linked list
 * @index: index of the node, beginning at 0.
 *
 * Return: pointer to the nth node, or NULL if the node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int y;
	listint_t *node;

	if (!head)
		return (NULL);

	node = head;
	for (y = 0; y < index; y++)
	{
		node = node->next;
		if (!node)
			return (NULL);
	}

	return (node);
}
