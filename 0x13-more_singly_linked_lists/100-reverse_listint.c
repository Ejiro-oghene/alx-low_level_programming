#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to the head of the listint_t linked list.
 *
 * Return: pointer to the 1st node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
		listint_t *prev = NULL, *next = NULL;

		if (head == NULL || *head == NULL)
			return (NULL);

		while ((*head)->next != NULL)
		{
			next = (*head)->next;
			(*head)->next = prev;
			prev = *head;
			*head = next;
		}
		(*head)->next = prev;

		return (*head);
}
