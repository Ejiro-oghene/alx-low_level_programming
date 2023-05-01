#include "lists.h"


/**
 * add_nodeint_end - Append a new node at the end of a listint_t list
 * @head: A pointer to the head of the linked list.
 * @n: value to store in the new node
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *currentnode;

	if (!head)
		return (NULL);

	newnode = malloc(sizeof(listint_t));
	if (!newnode)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (!*head)
		*head = newnode;
	else
	{
		currentnode = *head;
		while (currentnode->next)
			currentnode = currentnode->next;
		currentnode->next = newnode;
	}

	return (newnode);
}
