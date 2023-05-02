#include "lists.h"


/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head node
 * @idx: index of the list where new node should be added
 * @n: integer value to be stored in new node
 *
 * Return: Address of new node, or NULL if it fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *temp = *head;
	unsigned int m = 0;

	if (!head)
		return (NULL);
	newnode = malloc(sizeof(listint_t));
	if (!newnode)
		return (NULL);

	newnode->n = n;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}

	while (temp && m < idx - 1)
	{
		temp = temp->next;
		m++;
	}

	if (!temp)
	{
		free(newnode);
		return (NULL);
	}

	newnode->next = temp->next;
	temp->next = newnode;

	return (newnode);
}
