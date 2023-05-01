#include "lists.h"


/**
 * free_listint2 - frees listint_t list
 * @head: pointer to pointer to the head of the linked list
 *
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *currentnode, *nextnode;

	if (head == NULL)
		return;

	currentnode = *head;

	while (currentnode != NULL)
	{
		nextnode = currentnode->next;
		free(currentnode);
		currentnode = nextnode;
	}

	*head = NULL;
}
