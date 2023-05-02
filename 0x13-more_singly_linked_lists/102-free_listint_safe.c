#include "lists.h"


/**
 * free_listint_safe - sets free a listint_t list
 * @h: A pointer to the head of the listint_t list
 *
 * Return: size of list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t size = 0;

	if (!h || !*h)
		return (size);

	current = *h;
	while (current)
	{
		size++;
		next = current->next;
		free(current);
		if ((void *)next >= (void *)current)
		{
			*h = NULL;
			return (size);
		}
		current = next;
	}
	*h = NULL;
	return (size);
}
