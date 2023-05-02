#include "lists.h"


/**
 * print_listint_safe - prints a listint_t list.
 * @head: pointer to the list head.
 *
 * Return: numb of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp = head;
	size_t count = 0;

	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;

		if (temp <= temp->next)
		{
			printf("-> [%p] %d\n", (void *)temp->next, temp->next->n);
			break;
		}

		temp = temp->next;
	}

	return (count);
}
