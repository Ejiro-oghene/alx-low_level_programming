#include "lists.h"


/**
 * add_nodeint - Appends new node at the beginning of a listint_t list
 * @head: pointer to the pointer
 * @n: Value to store in new node.
 *
 * Return: Address of new node, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode = malloc(sizeof(listint_t));

	if (!newnode)
		return (NULL);

	newnode->n = n;
	newnode->next = *head;
	*head = newnode;

	return (newnode);
}
