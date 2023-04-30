#include "lists.h"


/**
 * listint_len - Function that returns the number of elements
 * @h: Pointer to the listint_t
 *
 * Return: The number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}

	return (len);
}
