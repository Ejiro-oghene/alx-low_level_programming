#include "lists.h"


/**
 * delete_nodeint_at_index - deletes the node at index of
 * a listint_t list
 * @head: head of linked list.
 * @index: index of node to be deleted, index starts at 0
 *
 * Return: 1 if success and -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
		listint_t *current, *prev_node;
		unsigned int q;

		if (head == NULL || *head == NULL)
			return (-1);

		current = *head;

		if (index == 0)
		{
			*head = (*head)->next;
			free(current);
			return (1);
		}

		for (q = 0; q < index && current != NULL; q++)
		{
			prev_node = current;
			current = current->next;
		}

		if (current == NULL)
			return (-1);

		prev_node->next = current->next;
		free(current);

		return (1);
}
