#include "lists.h"


/**
 * pop_listint - the function deletes the head node of a listint_t linked list
 * @head: pointer to pointer to the head of the linked list
 *
 * Return: head node's data (n), or 0 if list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (data);
}
