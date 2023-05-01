#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: pointer to the head of linked list.
 *
 * Return: nil
 */
void free_listint(listint_t *head)
{
	listint_t *currentnode;

	while (head != NULL)
	{
		currentnode = head;
		head = head->next;
		free(currentnode);
	}
}
